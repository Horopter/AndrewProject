/*
 * drawRectangle.h
 * 
 * Programmer: Anjali Aurora
 * Date: November 2025
 * 
 * Purpose: Function prototypes for drawing rectangles on an image.
 *          Supports three methods of rectangle specification.
 */

#ifndef DRAWRECTANGLE_H
#define DRAWRECTANGLE_H

#include "ColorImageClass.h"
#include "ColorClass.h"
#include "RowColumnLocationClass.h"

bool drawRectangleCorners(
    ColorImageClass &image,
    const RowColumnLocationClass &upperLeft,
    const RowColumnLocationClass &lowerRight,
    const ColorClass &color,
    bool fill);

bool drawRectangleDimensions(
    ColorImageClass &image,
    const RowColumnLocationClass &upperLeft,
    int numRows,
    int numCols,
    const ColorClass &color,
    bool fill);

bool drawRectangleCenter(
    ColorImageClass &image,
    const RowColumnLocationClass &center,
    int halfRows,
    int halfCols,
    const ColorClass &color,
    bool fill);

#endif

