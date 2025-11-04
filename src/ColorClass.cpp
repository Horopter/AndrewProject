/*
 * ColorClass.cpp
 * 
 * Programmer: Anjali Arora
 * Date: November 2025
 * 
 * Purpose: Implements the ColorClass for representing RGB colors.
 */

#include "ColorClass.h"

// Uses ColorClass::COLOR_MIN and ColorClass::COLOR_MAX from header

ColorClass::ColorClass()
{
  redValue = ColorClass::COLOR_MIN;
  greenValue = ColorClass::COLOR_MIN;
  blueValue = ColorClass::COLOR_MIN;
}

ColorClass::ColorClass(int inRed, int inGreen, int inBlue)
{
  if (inRed < ColorClass::COLOR_MIN)
  {
    redValue = ColorClass::COLOR_MIN;
  }
  else if (inRed > ColorClass::COLOR_MAX)
  {
    redValue = ColorClass::COLOR_MAX;
  }
  else
  {
    redValue = inRed;
  }

  if (inGreen < ColorClass::COLOR_MIN)
  {
    greenValue = ColorClass::COLOR_MIN;
  }
  else if (inGreen > ColorClass::COLOR_MAX)
  {
    greenValue = ColorClass::COLOR_MAX;
  }
  else
  {
    greenValue = inGreen;
  }

  if (inBlue < ColorClass::COLOR_MIN)
  {
    blueValue = ColorClass::COLOR_MIN;
  }
  else if (inBlue > ColorClass::COLOR_MAX)
  {
    blueValue = ColorClass::COLOR_MAX;
  }
  else
  {
    blueValue = inBlue;
  }
}

void ColorClass::setToBlack()
{
  redValue = ColorClass::COLOR_MIN;
  greenValue = ColorClass::COLOR_MIN;
  blueValue = ColorClass::COLOR_MIN;
}

void ColorClass::setToRed()
{
  redValue = ColorClass::COLOR_MAX;
  greenValue = ColorClass::COLOR_MIN;
  blueValue = ColorClass::COLOR_MIN;
}

void ColorClass::setToGreen()
{
  redValue = ColorClass::COLOR_MIN;
  greenValue = ColorClass::COLOR_MAX;
  blueValue = ColorClass::COLOR_MIN;
}

void ColorClass::setToBlue()
{
  redValue = ColorClass::COLOR_MIN;
  greenValue = ColorClass::COLOR_MIN;
  blueValue = ColorClass::COLOR_MAX;
}

void ColorClass::setToWhite()
{
  redValue = ColorClass::COLOR_MAX;
  greenValue = ColorClass::COLOR_MAX;
  blueValue = ColorClass::COLOR_MAX;
}

void ColorClass::setToSpecificColor(int inRed, int inGreen, int inBlue)
{
  if (inRed < ColorClass::COLOR_MIN)
  {
    redValue = ColorClass::COLOR_MIN;
  }
  else if (inRed > ColorClass::COLOR_MAX)
  {
    redValue = ColorClass::COLOR_MAX;
  }
  else
  {
    redValue = inRed;
  }

  if (inGreen < ColorClass::COLOR_MIN)
  {
    greenValue = ColorClass::COLOR_MIN;
  }
  else if (inGreen > ColorClass::COLOR_MAX)
  {
    greenValue = ColorClass::COLOR_MAX;
  }
  else
  {
    greenValue = inGreen;
  }

  if (inBlue < ColorClass::COLOR_MIN)
  {
    blueValue = ColorClass::COLOR_MIN;
  }
  else if (inBlue > ColorClass::COLOR_MAX)
  {
    blueValue = ColorClass::COLOR_MAX;
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

