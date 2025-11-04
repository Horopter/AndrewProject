/*
 * RowColumnClass.h
 * 
 * Programmer: Anjali Arora
 * Date: November 2025
 * 
 * Purpose: Defines the RowColumnClass which represents a
 *          location in an image using row and column coordinates.
 */

#ifndef ROWCOLUMNCLASS_H
#define ROWCOLUMNCLASS_H

class RowColumnClass
{
  private:
    int row;
    int col;

  public:
    // Default constructor
    RowColumnClass();

    // Constructor with row and column
    RowColumnClass(int inRow, int inCol);

    // Getters
    int getRow() const;
    int getCol() const;

    // Setters
    void setRow(int inRow);
    void setCol(int inCol);

    // Set both row and column
    void setRowCol(int inRow, int inCol);
};

#endif

