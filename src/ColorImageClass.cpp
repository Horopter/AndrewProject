/*
 * ColorImageClass.cpp
 * 
 * Programmer: Anjali Arora
 * Date: November 2025
 * 
 * Purpose: Implements the ColorImageClass for managing images with
 *          dynamic allocation.
 */

#include "ColorImageClass.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ColorImageClass::ColorImageClass()
{
  width = 0;
  height = 0;
  maxColorValue = 255;
  pixels = 0;
}

ColorImageClass::ColorImageClass(int inWidth, int inHeight, int inMaxColor)
{
  width = inWidth;
  height = inHeight;
  maxColorValue = inMaxColor;
  pixels = 0;
  allocatePixels(width, height);
  ColorClass black;
  initializeTo(black);
}

ColorImageClass::ColorImageClass(const ColorImageClass &rhs)
{
  width = 0;
  height = 0;
  maxColorValue = 255;
  pixels = 0;
  *this = rhs;
}

ColorImageClass::~ColorImageClass()
{
  deallocatePixels();
}

ColorImageClass& ColorImageClass::operator=(const ColorImageClass &rhs)
{
  if (this != &rhs)
  {
    deallocatePixels();
    width = rhs.width;
    height = rhs.height;
    maxColorValue = rhs.maxColorValue;
    if (rhs.pixels != 0)
    {
      allocatePixels(width, height);
      for (int i = 0; i < height; i++)
      {
        for (int j = 0; j < width; j++)
        {
          pixels[i][j] = rhs.pixels[i][j];
        }
      }
    }
  }
  return *this;
}

void ColorImageClass::allocatePixels(int inWidth, int inHeight)
{
  if (inWidth <= 0 || inHeight <= 0)
  {
    pixels = 0;
    return;
  }

  pixels = new ColorClass*[inHeight];
  for (int i = 0; i < inHeight; i++)
  {
    pixels[i] = new ColorClass[inWidth];
  }
}

void ColorImageClass::deallocatePixels()
{
  if (pixels != 0)
  {
    for (int i = 0; i < height; i++)
    {
      delete[] pixels[i];
    }
    delete[] pixels;
    pixels = 0;
  }
}

int ColorImageClass::getWidth() const
{
  return width;
}

int ColorImageClass::getHeight() const
{
  return height;
}

int ColorImageClass::getMaxColorValue() const
{
  return maxColorValue;
}

bool ColorImageClass::getPixel(int row, int col, ColorClass &outColor) const
{
  if (!isValidLocation(row, col))
  {
    return false;
  }
  outColor = pixels[row][col];
  return true;
}

bool ColorImageClass::setPixel(int row, int col, const ColorClass &inColor)
{
  if (!isValidLocation(row, col))
  {
    return false;
  }
  pixels[row][col] = inColor;
  return true;
}

void ColorImageClass::initializeTo(const ColorClass &inColor)
{
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      pixels[i][j] = inColor;
    }
  }
}

bool ColorImageClass::isValidLocation(int row, int col) const
{
  if (pixels == 0)
  {
    return false;
  }
  if (row < 0 || row >= height || col < 0 || col >= width)
  {
    return false;
  }
  return true;
}

bool ColorImageClass::readFromPpmFile(const char *fileName)
{
  ifstream inFile;
  inFile.open(fileName);

  if (inFile.fail())
  {
    inFile.close();
    cout << "Error: Unable to open PPM file: " << fileName << endl;
    return false;
  }

  const int MAX_LINE_LENGTH = 80;
  const char PPM_MAGIC_NUMBER[] = "P3";
  char magicNumber[MAX_LINE_LENGTH];
  inFile >> magicNumber;
  if (strcmp(magicNumber, PPM_MAGIC_NUMBER) != 0)
  {
    inFile.close();
    cout << "Error: Invalid PPM magic number in file: " << fileName 
         << endl;
    return false;
  }

  int inWidth, inHeight, inMaxColorValue;
  inFile >> inWidth >> inHeight >> inMaxColorValue;
  if (inFile.fail() || inWidth <= 0 || inHeight <= 0 || 
      inMaxColorValue <= 0)
  {
    inFile.close();
    cout << "Error: Invalid image dimensions or max color value in file: " 
         << fileName << endl;
    return false;
  }

  deallocatePixels();
  width = inWidth;
  height = inHeight;
  maxColorValue = inMaxColorValue;
  allocatePixels(width, height);

  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      int red, green, blue;
      inFile >> red >> green >> blue;
      if (inFile.fail() || red < 0 || red > maxColorValue ||
          green < 0 || green > maxColorValue ||
          blue < 0 || blue > maxColorValue)
      {
        inFile.close();
        cout << "Error: Invalid pixel data in file: " << fileName << endl;
        return false;
      }
      ColorClass pixelColor(red, green, blue);
      setPixel(i, j, pixelColor);
    }
  }

  inFile.close();
  return true;
}

bool ColorImageClass::writeToPpmFile(const char *fileName) const
{
  ofstream outFile;
  outFile.open(fileName);

  if (outFile.fail())
  {
    outFile.close();
    cout << "Error: Unable to create PPM file: " << fileName << endl;
    return false;
  }

  const char PPM_MAGIC_NUMBER[] = "P3";
  outFile << PPM_MAGIC_NUMBER << endl;
  outFile << width << " " << height << endl;
  outFile << maxColorValue << endl;

  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      ColorClass pixelColor;
      getPixel(i, j, pixelColor);
      outFile << pixelColor.getRed() << " " << pixelColor.getGreen() 
              << " " << pixelColor.getBlue() << " ";
    }
    outFile << endl;
  }

  outFile.close();
  return true;
}

bool ColorImageClass::insertImage(
    const ColorImageClass &sourceImage,
    const RowColumnClass &upperLeft,
    const ColorClass &transparencyColor)
{
  int startRow = upperLeft.getRow();
  int startCol = upperLeft.getCol();

  for (int i = 0; i < sourceImage.getHeight(); i++)
  {
    for (int j = 0; j < sourceImage.getWidth(); j++)
    {
      ColorClass sourcePixel;
      sourceImage.getPixel(i, j, sourcePixel);

      if (sourcePixel.getRed() != transparencyColor.getRed() ||
          sourcePixel.getGreen() != transparencyColor.getGreen() ||
          sourcePixel.getBlue() != transparencyColor.getBlue())
      {
        int targetRow = startRow + i;
        int targetCol = startCol + j;
        if (isValidLocation(targetRow, targetCol))
        {
          setPixel(targetRow, targetCol, sourcePixel);
        }
      }
    }
  }

  return true;
}

