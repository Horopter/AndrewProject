/*
 * RowColumnClass.cpp
 * 
 * Programmer: Anjali Arora
 * Date: November 2025
 * 
 * Purpose: Implements the RowColumnClass for representing
 *          row and column locations.
 */

#include "RowColumnClass.h"

RowColumnClass::RowColumnClass()
{
  row = 0;
  col = 0;
}

RowColumnClass::RowColumnClass(int inRow, int inCol)
{
  row = inRow;
  col = inCol;
}

int RowColumnClass::getRow() const
{
  return row;
}

int RowColumnClass::getCol() const
{
  return col;
}

void RowColumnClass::setRow(int inRow)
{
  row = inRow;
}

void RowColumnClass::setCol(int inCol)
{
  col = inCol;
}

void RowColumnClass::setRowCol(int inRow, int inCol)
{
  row = inRow;
  col = inCol;
}

