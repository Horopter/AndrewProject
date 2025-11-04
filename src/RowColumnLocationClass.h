/*
 * RowColumnLocationClass.h
 * 
 * Programmer: Anjali Aurora
 * Date: November 2025
 * 
 * Purpose: Defines the RowColumnLocationClass which represents a
 *          location in an image using row and column coordinates.
 */

#ifndef ROWCOLUMNLOCATIONCLASS_H
#define ROWCOLUMNLOCATIONCLASS_H

class RowColumnLocationClass
{
  private:
    int row;
    int col;

  public:
    // Default constructor
    RowColumnLocationClass();

    // Constructor with row and column
    RowColumnLocationClass(int inRow, int inCol);

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

