/*
 * insertImage.h
 * 
 * Programmer: Anjali Aurora
 * Date: November 2025
 * 
 * Purpose: Function prototype for inserting another image into the
 *          current image with transparency support.
 */

#ifndef INSERTIMAGE_H
#define INSERTIMAGE_H

#include "ColorImageClass.h"
#include "ColorClass.h"
#include "RowColumnLocationClass.h"

bool insertImage(
    ColorImageClass &image,
    const char *insertFileName,
    const RowColumnLocationClass &upperLeft,
    const ColorClass &transparencyColor);

#endif

