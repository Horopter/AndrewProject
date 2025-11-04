/*
 * ColorClass.cpp
 * 
 * Programmer: Anjali Arora
 * Date: November 2025
 * 
 * Purpose: Implements the ColorClass for representing RGB colors.
 */

#include "ColorClass.h"

const int COLOR_MIN = 0;
const int COLOR_MAX = 255;

ColorClass::ColorClass()
{
  redValue = COLOR_MIN;
  greenValue = COLOR_MIN;
  blueValue = COLOR_MIN;
}

ColorClass::ColorClass(int inRed, int inGreen, int inBlue)
{
  if (inRed < COLOR_MIN)
  {
    redValue = COLOR_MIN;
  }
  else if (inRed > COLOR_MAX)
  {
    redValue = COLOR_MAX;
  }
  else
  {
    redValue = inRed;
  }

  if (inGreen < COLOR_MIN)
  {
    greenValue = COLOR_MIN;
  }
  else if (inGreen > COLOR_MAX)
  {
    greenValue = COLOR_MAX;
  }
  else
  {
    greenValue = inGreen;
  }

  if (inBlue < COLOR_MIN)
  {
    blueValue = COLOR_MIN;
  }
  else if (inBlue > COLOR_MAX)
  {
    blueValue = COLOR_MAX;
  }
  else
  {
    blueValue = inBlue;
  }
}

void ColorClass::setToBlack()
{
  redValue = COLOR_MIN;
  greenValue = COLOR_MIN;
  blueValue = COLOR_MIN;
}

void ColorClass::setToRed()
{
  redValue = COLOR_MAX;
  greenValue = COLOR_MIN;
  blueValue = COLOR_MIN;
}

void ColorClass::setToGreen()
{
  redValue = COLOR_MIN;
  greenValue = COLOR_MAX;
  blueValue = COLOR_MIN;
}

void ColorClass::setToBlue()
{
  redValue = COLOR_MIN;
  greenValue = COLOR_MIN;
  blueValue = COLOR_MAX;
}

void ColorClass::setToWhite()
{
  redValue = COLOR_MAX;
  greenValue = COLOR_MAX;
  blueValue = COLOR_MAX;
}

void ColorClass::setToSpecificColor(int inRed, int inGreen, int inBlue)
{
  if (inRed < COLOR_MIN)
  {
    redValue = COLOR_MIN;
  }
  else if (inRed > COLOR_MAX)
  {
    redValue = COLOR_MAX;
  }
  else
  {
    redValue = inRed;
  }

  if (inGreen < COLOR_MIN)
  {
    greenValue = COLOR_MIN;
  }
  else if (inGreen > COLOR_MAX)
  {
    greenValue = COLOR_MAX;
  }
  else
  {
    greenValue = inGreen;
  }

  if (inBlue < COLOR_MIN)
  {
    blueValue = COLOR_MIN;
  }
  else if (inBlue > COLOR_MAX)
  {
    blueValue = COLOR_MAX;
  }
  else
  {
    blueValue = inBlue;
  }
}

int ColorClass::getRed() const
{
  return redValue;
}

int ColorClass::getGreen() const
{
  return greenValue;
}

int ColorClass::getBlue() const
{
  return blueValue;
}

