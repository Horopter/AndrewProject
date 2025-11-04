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
      for (int i = 0; i < patternRows; i++)
      {
        for (int j = 0; j < patternCols; j++)
        {
          patternData[i][j] = rhs.patternData[i][j];
        }
      }
    }
  }
  return *this;
}

void PatternClass::allocatePatternData(int inRows, int inCols)
{
  // Allocate a 2D array for the pattern
  if (inRows <= 0 || inCols <= 0)
  {
    patternData = 0;
    return;
  }

  patternRows = inRows;
  patternCols = inCols;
  patternData = new int*[patternRows];
  for (int i = 0; i < patternRows; i++)
  {
    patternData[i] = new int[patternCols];
  }
}

void PatternClass::deallocatePatternData()
{
  // Free the 2D pattern array if allocated
  if (patternData != 0)
  {
    for (int i = 0; i < patternRows; i++)
    {
      delete[] patternData[i];
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
    cout << "Error: Unable to open pattern file: " << fileName << endl;
    return false;
  }

  int inRows;
  int inCols;
  patternFile >> inRows;
  if (patternFile.fail() || inRows <= 0)
  {
    patternFile.close();
    cout << "Error: Invalid pattern dimensions in file: " << fileName 
         << endl;
    return false;
  }

  patternFile >> inCols;
  if (patternFile.fail() || inCols <= 0)
  {
    patternFile.close();
    cout << "Error: Invalid pattern dimensions in file: " << fileName 
         << endl;
    return false;
  }

  deallocatePatternData();
  allocatePatternData(inRows, inCols);

  int patternValue;
  for (int i = 0; i < patternRows; i++)
  {
    for (int j = 0; j < patternCols; j++)
    {
      patternFile >> patternValue;
      if (patternFile.fail())
      {
        patternFile.close();
        deallocatePatternData();
        cout << "Error: Invalid pattern data in file: " << fileName 
             << endl;
        return false;
      }
      patternData[i][j] = patternValue;
    }
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

  for (int i = 0; i < patternRows; i++)
  {
    for (int j = 0; j < patternCols; j++)
    {
      if (patternData[i][j] == 1)
      {
        int imageRow = startRow + i;
        int imageCol = startCol + j;
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

