/*
 * ColorClass.cpp
 * 
 * Programmer: Anjali Arora
 * Date: November 2025
 * 
 * Purpose: Implements the ColorClass for representing RGB colors.
 */

#include "ColorClass.h"
#include <fstream>
#include <iostream>
using namespace std;

// Uses MIN_COLOR_VALUE and MAX_COLOR_VALUE from Constants.h

ColorClass::ColorClass()
{
  redValue = MIN_COLOR_VALUE;
  greenValue = MIN_COLOR_VALUE;
  blueValue = MIN_COLOR_VALUE;
}

ColorClass::ColorClass(int inRed, int inGreen, int inBlue)
{
  if (inRed < MIN_COLOR_VALUE)
  {
    redValue = MIN_COLOR_VALUE;
  }
  else if (inRed > MAX_COLOR_VALUE)
  {
    redValue = MAX_COLOR_VALUE;
  }
  else
  {
    redValue = inRed;
  }

  if (inGreen < MIN_COLOR_VALUE)
  {
    greenValue = MIN_COLOR_VALUE;
  }
  else if (inGreen > MAX_COLOR_VALUE)
  {
    greenValue = MAX_COLOR_VALUE;
  }
  else
  {
    greenValue = inGreen;
  }

  if (inBlue < MIN_COLOR_VALUE)
  {
    blueValue = MIN_COLOR_VALUE;
  }
  else if (inBlue > MAX_COLOR_VALUE)
  {
    blueValue = MAX_COLOR_VALUE;
  }
  else
  {
    blueValue = inBlue;
  }
}

void ColorClass::setToBlack()
{
  redValue = MIN_COLOR_VALUE;
  greenValue = MIN_COLOR_VALUE;
  blueValue = MIN_COLOR_VALUE;
}

void ColorClass::setToRed()
{
  redValue = MAX_COLOR_VALUE;
  greenValue = MIN_COLOR_VALUE;
  blueValue = MIN_COLOR_VALUE;
}

void ColorClass::setToGreen()
{
  redValue = MIN_COLOR_VALUE;
  greenValue = MAX_COLOR_VALUE;
  blueValue = MIN_COLOR_VALUE;
}

void ColorClass::setToBlue()
{
  redValue = MIN_COLOR_VALUE;
  greenValue = MIN_COLOR_VALUE;
  blueValue = MAX_COLOR_VALUE;
}

void ColorClass::setToWhite()
{
  redValue = MAX_COLOR_VALUE;
  greenValue = MAX_COLOR_VALUE;
  blueValue = MAX_COLOR_VALUE;
}

void ColorClass::setToSpecificColor(int inRed, int inGreen, int inBlue)
{
  if (inRed < MIN_COLOR_VALUE)
  {
    redValue = MIN_COLOR_VALUE;
  }
  else if (inRed > MAX_COLOR_VALUE)
  {
    redValue = MAX_COLOR_VALUE;
  }
  else
  {
    redValue = inRed;
  }

  if (inGreen < MIN_COLOR_VALUE)
  {
    greenValue = MIN_COLOR_VALUE;
  }
  else if (inGreen > MAX_COLOR_VALUE)
  {
    greenValue = MAX_COLOR_VALUE;
  }
  else
  {
    greenValue = inGreen;
  }

  if (inBlue < MIN_COLOR_VALUE)
  {
    blueValue = MIN_COLOR_VALUE;
  }
  else if (inBlue > MAX_COLOR_VALUE)
  {
    blueValue = MAX_COLOR_VALUE;
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

bool ColorClass::readFromFile(ifstream &inFile, int maxColorValue)
{
  int red, green, blue;
  inFile >> red >> green >> blue;
  
  // Validate that components are within allowed range
  if (inFile.fail() || red < MIN_COLOR_VALUE || red > maxColorValue ||
      green < MIN_COLOR_VALUE || green > maxColorValue ||
      blue < MIN_COLOR_VALUE || blue > maxColorValue)
  {
    return false;
  }
  
  // Set the color values (clamping will be handled by setToSpecificColor)
  setToSpecificColor(red, green, blue);
  return true;
}

bool ColorClass::writeToFile(ofstream &outFile) const
{
  outFile << redValue << " " << greenValue << " " << blueValue << " ";
  return !outFile.fail();
}

