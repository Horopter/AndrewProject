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
#include "Constants.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ColorImageClass::ColorImageClass()
{
  width = 0;
  height = 0;
  maxColorValue = MAX_COLOR_VALUE;
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
  maxColorValue = MAX_COLOR_VALUE;
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
      for (int rowIndex = 0; rowIndex < height; rowIndex++)
      {
        for (int colIndex = 0; colIndex < width; colIndex++)
        {
          pixels[rowIndex][colIndex] = rhs.pixels[rowIndex][colIndex];
        }
      }
    }
  }
  return *this;
}

void ColorImageClass::allocatePixels(int inWidth, int inHeight)
{
  if (inWidth < MIN_IMAGE_DIM || inHeight < MIN_IMAGE_DIM)
  {
    pixels = 0;
    return;
  }

  pixels = new ColorClass*[inHeight];
  for (int rowIndex = 0; rowIndex < inHeight; rowIndex++)
  {
    pixels[rowIndex] = new ColorClass[inWidth];
  }
}

void ColorImageClass::deallocatePixels()
{
  if (pixels != 0)
  {
    for (int rowIndex = 0; rowIndex < height; rowIndex++)
    {
      delete[] pixels[rowIndex];
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
  for (int rowIndex = 0; rowIndex < height; rowIndex++)
  {
    for (int colIndex = 0; colIndex < width; colIndex++)
    {
      pixels[rowIndex][colIndex] = inColor;
    }
  }
}

bool ColorImageClass::isValidLocation(int row, int col) const
{
  if (pixels == 0)
  {
    return false;
  }
  if (row < MIN_COORDINATE || row >= height || 
      col < MIN_COORDINATE || col >= width)
  {
    return false;
  }
  return true;
}

bool ColorImageClass::readFromPpmFile(const string &fileName)
{
  // Open the PPM file for reading (ASCII P3 format)
  ifstream inFile;
  inFile.open(fileName.c_str());

  // Fail if file cannot be opened
  if (inFile.fail())
  {
    inFile.close();
    cout << ERROR_UNABLE_TO_OPEN_PPM << fileName << endl;
    return false;
  }

  // Read and validate the PPM magic number
  string magicNumber;
  inFile >> magicNumber;
  if (magicNumber != PPM_MAGIC_NUMBER)
  {
    inFile.close();
    cout << ERROR_INVALID_PPM_MAGIC << fileName << endl;
    return false;
  }

  int inWidth, inHeight, inMaxColorValue;
  inFile >> inWidth >> inHeight >> inMaxColorValue;
  // Validate width, height, and max color value
  if (inFile.fail() || inWidth < MIN_IMAGE_DIM || inHeight < MIN_IMAGE_DIM ||
      inWidth > MAX_IMAGE_DIM || inHeight > MAX_IMAGE_DIM ||
      inMaxColorValue != MAX_COLOR_VALUE)
  {
    inFile.close();
    cout << ERROR_INVALID_IMAGE_DIMENSIONS << fileName << endl;
    return false;
  }

  // Resize this image to match the input
  deallocatePixels();
  width = inWidth;
  height = inHeight;
  maxColorValue = inMaxColorValue;
  allocatePixels(width, height);

  for (int rowIndex = 0; rowIndex < height; rowIndex++)
  {
    for (int colIndex = 0; colIndex < width; colIndex++)
    {
      // Ask the ColorClass to read its own RGB values from the file
      if (!pixels[rowIndex][colIndex].readFromFile(inFile, maxColorValue))
      {
        inFile.close();
        cout << ERROR_INVALID_PIXEL_DATA << fileName << endl;
        return false;
      }
    }
  }

  // Check for extra data after reading all expected pixels
  // Try to read one more token - if successful, there's extra data
  int extraValue;
  inFile >> extraValue;
  if (!inFile.fail() && !inFile.eof())
  {
    inFile.close();
    cout << ERROR_EXTRA_DATA << fileName << endl;
    return false;
  }

  inFile.close();
  return true;
}

bool ColorImageClass::writeToPpmFile(const string &fileName) const
{
  // Open the output file (ASCII P3 format)
  ofstream outFile;
  outFile.open(fileName.c_str());

  // Fail if file cannot be created
  if (outFile.fail())
  {
    outFile.close();
    cout << ERROR_UNABLE_TO_CREATE_PPM << fileName << endl;
    return false;
  }

  // Write header: magic, size, and max color
  outFile << PPM_MAGIC_NUMBER << endl;
  outFile << width << " " << height << endl;
  outFile << maxColorValue << endl;

  // Write pixel data row by row
  for (int rowIndex = 0; rowIndex < height; rowIndex++)
  {
    for (int colIndex = 0; colIndex < width; colIndex++)
    {
      // Ask the ColorClass to write its own RGB values to the file
      if (!pixels[rowIndex][colIndex].writeToFile(outFile))
      {
        outFile.close();
        cout << ERROR_UNABLE_TO_WRITE_PIXEL << fileName << endl;
        return false;
      }
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

  for (int sourceRowIndex = 0; sourceRowIndex < sourceImage.getHeight(); 
       sourceRowIndex++)
  {
    for (int sourceColIndex = 0; sourceColIndex < sourceImage.getWidth(); 
         sourceColIndex++)
    {
      ColorClass sourcePixel;
      sourceImage.getPixel(sourceRowIndex, sourceColIndex, sourcePixel);

      if (sourcePixel.getRed() != transparencyColor.getRed() ||
          sourcePixel.getGreen() != transparencyColor.getGreen() ||
          sourcePixel.getBlue() != transparencyColor.getBlue())
      {
        int targetRow = startRow + sourceRowIndex;
        int targetCol = startCol + sourceColIndex;
        if (isValidLocation(targetRow, targetCol))
        {
          setPixel(targetRow, targetCol, sourcePixel);
        }
      }
    }
  }

  return true;
}

