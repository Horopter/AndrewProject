/*
 * RectangleClass.h
 * 
 * Programmer: Anjali Arora
 * Date: November 2025
 * 
 * Purpose: Defines the RectangleClass which represents a rectangle
 *          that can be drawn onto an image.
 */

#ifndef RECTANGLECLASS_H
#define RECTANGLECLASS_H

#include "ColorImageClass.h"
#include "ColorClass.h"
#include "RowColumnClass.h"

class RectangleClass
{
  private:
    int startRow;
    int endRow;
    int startCol;
    int endCol;
    ColorClass color;
    bool fill;

    void normalizeCoordinates();

  public:
    RectangleClass();
    RectangleClass(
        const RowColumnClass &upperLeft,
        const RowColumnClass &lowerRight,
        const ColorClass &inColor,
        bool inFill);

    void setUsingCorners(
        const RowColumnClass &upperLeft,
        const RowColumnClass &lowerRight);
    void setUsingDimensions(
        const RowColumnClass &upperLeft,
        int numRows,
        int numCols);
    void setUsingCenter(
        const RowColumnClass &center,
        int halfRows,
        int halfCols);
    void setColor(const ColorClass &inColor);
    void setFill(bool inFill);

    bool drawOntoImage(ColorImageClass &image) const;
};

#endif

