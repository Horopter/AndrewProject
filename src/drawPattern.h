/*
 * drawPattern.h
 * 
 * Programmer: Anjali Aurora
 * Date: November 2025
 * 
 * Purpose: Function prototype for drawing a pattern from a file
 *          onto an image.
 */

#ifndef DRAWPATTERN_H
#define DRAWPATTERN_H

#include "ColorImageClass.h"
#include "ColorClass.h"
#include "RowColumnLocationClass.h"

bool drawPattern(
    ColorImageClass &image,
    const char *patternFileName,
    const RowColumnLocationClass &upperLeft,
    const ColorClass &color);

#endif

