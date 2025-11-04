/*
 * ColorClass.cpp
 * 
 * Programmer: Anjali Aurora
 * Date: November 2025
 * 
 * Purpose: Implements the ColorClass which represents a color using
 *          RGB values.
 */

#include "ColorClass.h"

const int COLOR_MIN = 0;
const int COLOR_MAX = 255;

ColorClass::ColorClass()
{
  red = COLOR_MIN;
  green = COLOR_MIN;
  blue = COLOR_MIN;
}

ColorClass::ColorClass(int inRed, int inGreen, int inBlue)
{
  red = inRed;
  green = inGreen;
  blue = inBlue;
}

int ColorClass::getRed() const
{
  return red;
}

int ColorClass::getGreen() const
{
  return green;
}

int ColorClass::getBlue() const
{
  return blue;
}

void ColorClass::setRed(int inRed)
{
  red = inRed;
}

void ColorClass::setGreen(int inGreen)
{
  green = inGreen;
}

void ColorClass::setBlue(int inBlue)
{
  blue = inBlue;
}

void ColorClass::setTo(int inRed, int inGreen, int inBlue)
{
  red = inRed;
  green = inGreen;
  blue = inBlue;
}

void ColorClass::setToRed()
{
  red = COLOR_MAX;
  green = COLOR_MIN;
  blue = COLOR_MIN;
}

void ColorClass::setToGreen()
{
  red = COLOR_MIN;
  green = COLOR_MAX;
  blue = COLOR_MIN;
}

void ColorClass::setToBlue()
{
  red = COLOR_MIN;
  green = COLOR_MIN;
  blue = COLOR_MAX;
}

void ColorClass::setToBlack()
{
  red = COLOR_MIN;
  green = COLOR_MIN;
  blue = COLOR_MIN;
}

void ColorClass::setToWhite()
{
  red = COLOR_MAX;
  green = COLOR_MAX;
  blue = COLOR_MAX;
}

bool ColorClass::equals(const ColorClass &rhs) const
{
  return (red == rhs.red && green == rhs.green && blue == rhs.blue);
}

