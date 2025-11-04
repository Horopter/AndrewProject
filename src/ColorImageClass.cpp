/*
 * ColorImageClass.cpp
 * 
 * Programmer: Anjali Aurora
 * Date: November 2025
 * 
 * Purpose: Implements the ColorImageClass which represents an image
 *          using a 2D array of ColorClass objects with dynamic allocation.
 */

#include "ColorImageClass.h"

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
  allocatePixels(inWidth, inHeight);
}

ColorImageClass::ColorImageClass(const ColorImageClass &rhs)
{
  width = rhs.width;
  height = rhs.height;
  maxColorValue = rhs.maxColorValue;
  allocatePixels(width, height);

  // Copy all pixels
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      pixels[i][j] = rhs.pixels[i][j];
    }
  }
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
    allocatePixels(width, height);

    // Copy all pixels
    for (int i = 0; i < height; i++)
    {
      for (int j = 0; j < width; j++)
      {
        pixels[i][j] = rhs.pixels[i][j];
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
  if (isValidLocation(row, col))
  {
    outColor = pixels[row][col];
    return true;
  }
  return false;
}

bool ColorImageClass::setPixel(int row, int col, const ColorClass &inColor)
{
  if (isValidLocation(row, col))
  {
    pixels[row][col] = inColor;
    return true;
  }
  return false;
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
  return (row >= 0 && row < height && col >= 0 && col < width);
}

