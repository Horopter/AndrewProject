/*
 * writePpmFile.cpp
 * 
 * Programmer: Anjali Aurora
 * Date: November 2025
 * 
 * Purpose: Implements function to write a ColorImageClass object
 *          to a PPM file.
 */

#include "writePpmFile.h"
#include <iostream>
#include <fstream>
using namespace std;

const char PPM_MAGIC_NUMBER[] = "P3";

bool writePpmFile(const char *fileName, const ColorImageClass &inImage)
{
  ofstream outFile;
  outFile.open(fileName);

  if (outFile.fail())
  {
    outFile.close();
    return false;
  }

  // Write magic number
  outFile << PPM_MAGIC_NUMBER << endl;
  if (outFile.fail())
  {
    outFile.close();
    return false;
  }

  // Write width and height
  outFile << inImage.getWidth() << " " << inImage.getHeight() << endl;
  if (outFile.fail())
  {
    outFile.close();
    return false;
  }

  // Write max color value
  outFile << inImage.getMaxColorValue() << endl;
  if (outFile.fail())
  {
    outFile.close();
    return false;
  }

  // Write pixel data
  ColorClass pixelColor;
  for (int i = 0; i < inImage.getHeight(); i++)
  {
    for (int j = 0; j < inImage.getWidth(); j++)
    {
      inImage.getPixel(i, j, pixelColor);
      outFile << pixelColor.getRed() << " "
              << pixelColor.getGreen() << " "
              << pixelColor.getBlue() << " ";
      if (outFile.fail())
      {
        outFile.close();
        return false;
      }
    }
    outFile << endl;
  }

  outFile.close();
  return true;
}

