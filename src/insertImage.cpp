/*
 * insertImage.cpp
 * 
 * Programmer: Anjali Aurora
 * Date: November 2025
 * 
 * Purpose: Implements function to insert another PPM image into the
 *          current image. Pixels matching the transparency color
 *          are not drawn.
 */

#include "insertImage.h"
#include "readPpmFile.h"

bool insertImage(
    ColorImageClass &image,
    const char *insertFileName,
    const RowColumnLocationClass &upperLeft,
    const ColorClass &transparencyColor)
{
  // Read the image to insert
  ColorImageClass insertImg;
  if (!readPpmFile(insertFileName, insertImg))
  {
    return false;
  }

  int startRow = upperLeft.getRow();
  int startCol = upperLeft.getCol();
  ColorClass pixelColor;

  // Copy pixels from insert image to main image
  for (int i = 0; i < insertImg.getHeight(); i++)
  {
    for (int j = 0; j < insertImg.getWidth(); j++)
    {
      insertImg.getPixel(i, j, pixelColor);

      // Only draw if not transparent
      if (!pixelColor.equals(transparencyColor))
      {
        int imageRow = startRow + i;
        int imageCol = startCol + j;
        if (image.isValidLocation(imageRow, imageCol))
        {
          image.setPixel(imageRow, imageCol, pixelColor);
        }
      }
    }
  }

  return true;
}

