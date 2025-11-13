/*
 * PatternClass.cpp
 * 
 * Programmer: Anjali Arora
 * Date: November 2025
 * 
 * Purpose: Implements the PatternClass for reading and drawing
 *          patterns.
 */

#include "PatternClass.h"
#include "Constants.h"
#include <iostream>
#include <fstream>
using namespace std;

PatternClass::PatternClass()
{
  patternRows = 0;
  patternCols = 0;
  patternData = 0;
}

PatternClass::~PatternClass()
{
  deallocatePatternData();
}

PatternClass::PatternClass(const PatternClass &rhs)
{
  patternRows = 0;
  patternCols = 0;
  patternData = 0;
  *this = rhs;
}

PatternClass& PatternClass::operator=(const PatternClass &rhs)
{
  if (this != &rhs)
  {
    deallocatePatternData();
    if (rhs.patternData != 0)
    {
      allocatePatternData(rhs.patternRows, rhs.patternCols);
      for (int rowIndex = 0; rowIndex < patternRows; rowIndex++)
      {
        for (int colIndex = 0; colIndex < patternCols; colIndex++)
        {
          patternData[rowIndex][colIndex] = 
            rhs.patternData[rowIndex][colIndex];
        }
      }
    }
  }
  return *this;
}

void PatternClass::allocatePatternData(int inRows, int inCols)
{
  // Allocate a 2D array for the pattern
  if (inRows < MIN_IMAGE_DIM || inCols < MIN_IMAGE_DIM)
  {
    patternData = 0;
    return;
  }

  patternRows = inRows;
  patternCols = inCols;
  patternData = new int*[patternRows];
  for (int rowIndex = 0; rowIndex < patternRows; rowIndex++)
  {
    patternData[rowIndex] = new int[patternCols];
  }
}

void PatternClass::deallocatePatternData()
{
  // Free the 2D pattern array if allocated
  if (patternData != 0)
  {
    for (int rowIndex = 0; rowIndex < patternRows; rowIndex++)
    {
      delete[] patternData[rowIndex];
    }
    delete[] patternData;
    patternData = 0;
  }
  patternRows = 0;
  patternCols = 0;
}

bool PatternClass::readPatternFromFile(const char *fileName)
{
  // Open the pattern file and read rows, cols, then values
  ifstream patternFile;
  patternFile.open(fileName);

  if (patternFile.fail())
  {
    patternFile.close();
    cout << ERROR_UNABLE_TO_OPEN_PATTERN << fileName << endl;
    return false;
  }

  int inRows;
  int inCols;
  patternFile >> inRows;
  if (patternFile.fail() || inRows < MIN_IMAGE_DIM || 
      inRows > MAX_IMAGE_DIM)
  {
    patternFile.close();
    cout << ERROR_INVALID_PATTERN_DIMENSIONS << fileName << endl;
    return false;
  }

  patternFile >> inCols;
  if (patternFile.fail() || inCols < MIN_IMAGE_DIM || 
      inCols > MAX_IMAGE_DIM)
  {
    patternFile.close();
    cout << ERROR_INVALID_PATTERN_DIMENSIONS << fileName << endl;
    return false;
  }

  deallocatePatternData();
  allocatePatternData(inRows, inCols);

  int patternValue;
  for (int rowIndex = 0; rowIndex < patternRows; rowIndex++)
  {
    for (int colIndex = 0; colIndex < patternCols; colIndex++)
    {
      patternFile >> patternValue;
      if (patternFile.fail())
      {
        patternFile.close();
        deallocatePatternData();
        cout << ERROR_INVALID_PATTERN_DATA << fileName << endl;
        return false;
      }
      patternData[rowIndex][colIndex] = patternValue;
    }
  }

  // Check for extra data after reading all expected pattern values
  int extraValue;
  patternFile >> extraValue;
  if (!patternFile.fail() && !patternFile.eof())
  {
    patternFile.close();
    deallocatePatternData();
    cout << ERROR_INVALID_PATTERN_DATA << fileName << endl;
    return false;
  }

  patternFile.close();
  return true;
}

bool PatternClass::drawOntoImage(
    ColorImageClass &image,
    const RowColumnClass &upperLeft,
    const ColorClass &color) const
{
  // Draw pattern cells with 1 onto the image using the given color
  if (patternData == 0)
  {
    return false;
  }

  int startRow = upperLeft.getRow();
  int startCol = upperLeft.getCol();

  for (int patternRowIndex = 0; patternRowIndex < patternRows; 
       patternRowIndex++)
  {
    for (int patternColIndex = 0; patternColIndex < patternCols; 
         patternColIndex++)
    {
      if (patternData[patternRowIndex][patternColIndex] == 1)
      {
        int imageRow = startRow + patternRowIndex;
        int imageCol = startCol + patternColIndex;
        if (image.isValidLocation(imageRow, imageCol))
        {
          image.setPixel(imageRow, imageCol, color);
        }
      }
    }
  }

  return true;
}

int PatternClass::getNumRows() const
{
  return patternRows;
}

int PatternClass::getNumCols() const
{
  return patternCols;
}

