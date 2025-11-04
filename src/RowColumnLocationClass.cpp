/*
 * RowColumnLocationClass.cpp
 * 
 * Programmer: Anjali Aurora
 * Date: November 2025
 * 
 * Purpose: Implements the RowColumnLocationClass which represents a
 *          location in an image using row and column coordinates.
 */

#include "RowColumnLocationClass.h"

RowColumnLocationClass::RowColumnLocationClass()
{
  row = 0;
  col = 0;
}

RowColumnLocationClass::RowColumnLocationClass(int inRow, int inCol)
{
  row = inRow;
  col = inCol;
}

int RowColumnLocationClass::getRow() const
{
  return row;
}

int RowColumnLocationClass::getCol() const
{
  return col;
}

void RowColumnLocationClass::setRow(int inRow)
{
  row = inRow;
}

void RowColumnLocationClass::setCol(int inCol)
{
  col = inCol;
}

void RowColumnLocationClass::setRowCol(int inRow, int inCol)
{
  row = inRow;
  col = inCol;
}

