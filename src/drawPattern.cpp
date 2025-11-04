/*
 * drawPattern.cpp
 * 
 * Programmer: Anjali Aurora
 * Date: November 2025
 * 
 * Purpose: Implements function to draw a pattern from a file onto
 *          an image. Pattern file format: first line has rows and
 *          columns, then 0s and 1s where 1 means draw pixel.
 */

#include "drawPattern.h"
#include <iostream>
#include <fstream>
using namespace std;

bool drawPattern(
    ColorImageClass &image,
    const char *patternFileName,
    const RowColumnLocationClass &upperLeft,
    const ColorClass &color)
{
  ifstream patternFile;
  patternFile.open(patternFileName);

  if (patternFile.fail())
  {
    patternFile.close();
    return false;
  }

  // Read pattern dimensions
  int patternRows;
  int patternCols;
  patternFile >> patternRows;
  if (patternFile.fail() || patternRows <= 0)
  {
    patternFile.close();
    return false;
  }

  patternFile >> patternCols;
  if (patternFile.fail() || patternCols <= 0)
  {
    patternFile.close();
    return false;
  }

  // Read pattern data
  int patternValue;
  int startRow = upperLeft.getRow();
  int startCol = upperLeft.getCol();

  for (int i = 0; i < patternRows; i++)
  {
    for (int j = 0; j < patternCols; j++)
    {
      patternFile >> patternValue;
      if (patternFile.fail())
      {
        patternFile.close();
        return false;
      }

      // If pattern value is 1, draw pixel
      if (patternValue == 1)
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

  patternFile.close();
  return true;
}

