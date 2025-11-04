/*
 * RectangleClass.cpp
 * 
 * Programmer: Anjali Arora
 * Date: November 2025
 * 
 * Purpose: Implements the RectangleClass for drawing rectangles.
 */

#include "RectangleClass.h"

RectangleClass::RectangleClass()
{
  startRow = 0;
  endRow = 0;
  startCol = 0;
  endCol = 0;
  color.setToBlack();
  fill = false;
}

RectangleClass::RectangleClass(
    const RowColumnClass &upperLeft,
    const RowColumnClass &lowerRight,
    const ColorClass &inColor,
    bool inFill)
{
  startRow = upperLeft.getRow();
  endRow = lowerRight.getRow();
  startCol = upperLeft.getCol();
  endCol = lowerRight.getCol();
  color = inColor;
  fill = inFill;
  normalizeCoordinates();
}


void RectangleClass::normalizeCoordinates()
{
  if (startRow > endRow)
  {
    int temp = startRow;
    startRow = endRow;
    endRow = temp;
  }
  if (startCol > endCol)
  {
    int temp = startCol;
    startCol = endCol;
    endCol = temp;
  }
}

void RectangleClass::setUsingCorners(
    const RowColumnClass &upperLeft,
    const RowColumnClass &lowerRight)
{
  startRow = upperLeft.getRow();
  endRow = lowerRight.getRow();
  startCol = upperLeft.getCol();
  endCol = lowerRight.getCol();
  normalizeCoordinates();
}

void RectangleClass::setUsingDimensions(
    const RowColumnClass &upperLeft,
    int numRows,
    int numCols)
{
  startRow = upperLeft.getRow();
  startCol = upperLeft.getCol();
  endRow = startRow + numRows - 1;
  endCol = startCol + numCols - 1;
  normalizeCoordinates();
}

void RectangleClass::setUsingCenter(
    const RowColumnClass &center,
    int halfRows,
    int halfCols)
{
  int centerRow = center.getRow();
  int centerCol = center.getCol();
  startRow = centerRow - halfRows;
  endRow = centerRow + halfRows;
  startCol = centerCol - halfCols;
  endCol = centerCol + halfCols;
  normalizeCoordinates();
}

void RectangleClass::setColor(const ColorClass &inColor)
{
  color = inColor;
}

void RectangleClass::setFill(bool inFill)
{
  fill = inFill;
}

bool RectangleClass::drawOntoImage(ColorImageClass &image) const
{
  for (int i = startRow; i <= endRow; i++)
  {
    for (int j = startCol; j <= endCol; j++)
    {
      if (image.isValidLocation(i, j))
      {
        if (fill)
        {
          image.setPixel(i, j, color);
        }
        else
        {
          if (i == startRow || i == endRow || j == startCol || j == endCol)
          {
            image.setPixel(i, j, color);
          }
        }
      }
    }
  }
  return true;
}

