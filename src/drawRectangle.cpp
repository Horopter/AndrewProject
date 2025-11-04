/*
 * drawRectangle.cpp
 * 
 * Programmer: Anjali Aurora
 * Date: November 2025
 * 
 * Purpose: Implements functions for drawing rectangles on an image.
 */

#include "drawRectangle.h"

bool drawRectangleCorners(
    ColorImageClass &image,
    const RowColumnLocationClass &upperLeft,
    const RowColumnLocationClass &lowerRight,
    const ColorClass &color,
    bool fill)
{
  int startRow = upperLeft.getRow();
  int endRow = lowerRight.getRow();
  int startCol = upperLeft.getCol();
  int endCol = lowerRight.getCol();

  // Ensure start <= end
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

  // Draw rectangle
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
          // Draw only border (top, bottom, left, right edges)
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

bool drawRectangleDimensions(
    ColorImageClass &image,
    const RowColumnLocationClass &upperLeft,
    int numRows,
    int numCols,
    const ColorClass &color,
    bool fill)
{
  int startRow = upperLeft.getRow();
  int startCol = upperLeft.getCol();
  int endRow = startRow + numRows - 1;
  int endCol = startCol + numCols - 1;

  // Draw rectangle
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
          // Draw only border
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

bool drawRectangleCenter(
    ColorImageClass &image,
    const RowColumnLocationClass &center,
    int halfRows,
    int halfCols,
    const ColorClass &color,
    bool fill)
{
  int centerRow = center.getRow();
  int centerCol = center.getCol();
  int startRow = centerRow - halfRows;
  int endRow = centerRow + halfRows;
  int startCol = centerCol - halfCols;
  int endCol = centerCol + halfCols;

  // Draw rectangle
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
          // Draw only border
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

