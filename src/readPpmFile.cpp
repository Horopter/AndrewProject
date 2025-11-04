/*
 * readPpmFile.cpp
 * 
 * Programmer: Anjali Aurora
 * Date: November 2025
 * 
 * Purpose: Implements function to read a PPM file and create a
 *          ColorImageClass object.
 */

#include "readPpmFile.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

const int MAX_LINE_LENGTH = 80;
const char PPM_MAGIC_NUMBER[] = "P3";

bool readPpmFile(const char *fileName, ColorImageClass &outImage)
{
  ifstream inFile;
  inFile.open(fileName);

  if (inFile.fail())
  {
    inFile.close();
    return false;
  }

  // Read magic number
  char magicNumber[MAX_LINE_LENGTH];
  inFile >> magicNumber;
  if (inFile.fail() || strcmp(magicNumber, PPM_MAGIC_NUMBER) != 0)
  {
    inFile.close();
    return false;
  }

  // Read width and height
  int width;
  int height;
  inFile >> width;
  if (inFile.fail() || width <= 0)
  {
    inFile.close();
    return false;
  }

  inFile >> height;
  if (inFile.fail() || height <= 0)
  {
    inFile.close();
    return false;
  }

  // Read max color value
  int maxColorValue;
  inFile >> maxColorValue;
  if (inFile.fail() || maxColorValue <= 0)
  {
    inFile.close();
    return false;
  }

  // Create new image with these dimensions
  ColorImageClass newImage(width, height, maxColorValue);

  // Read pixel data
  int red;
  int green;
  int blue;
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      inFile >> red;
      if (inFile.fail())
      {
        inFile.close();
        return false;
      }

      inFile >> green;
      if (inFile.fail())
      {
        inFile.close();
        return false;
      }

      inFile >> blue;
      if (inFile.fail())
      {
        inFile.close();
        return false;
      }

      ColorClass pixelColor(red, green, blue);
      newImage.setPixel(i, j, pixelColor);
    }
  }

  // Check for any remaining errors
  if (inFile.fail() && !inFile.eof())
  {
    inFile.close();
    return false;
  }

  inFile.close();
  outImage = newImage;
  return true;
}

