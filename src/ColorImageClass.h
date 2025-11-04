/*
 * ColorImageClass.h
 * 
 * Programmer: Anjali Arora
 * Date: November 2025
 * 
 * Purpose: Defines the ColorImageClass which represents an image using
 *          a 2D array of ColorClass objects with dynamic allocation.
 */

#ifndef COLORIMAGECLASS_H
#define COLORIMAGECLASS_H

#include "ColorClass.h"
#include "RowColumnClass.h"

class ColorImageClass
{
  private:
    int width;
    int height;
    int maxColorValue;
    ColorClass **pixels;

    // Helper function to allocate pixel array
    void allocatePixels(int inWidth, int inHeight);

    // Helper function to deallocate pixel array
    void deallocatePixels();

  public:
    // Default constructor
    ColorImageClass();

    // Constructor with dimensions
    ColorImageClass(int inWidth, int inHeight, int inMaxColor);

    // Copy constructor
    ColorImageClass(const ColorImageClass &rhs);

    // Destructor
    ~ColorImageClass();

    // Assignment operator
    ColorImageClass& operator=(const ColorImageClass &rhs);

    // Getters
    int getWidth() const;
    int getHeight() const;
    int getMaxColorValue() const;

    // Get pixel color at location
    bool getPixel(int row, int col, ColorClass &outColor) const;

    // Set pixel color at location
    bool setPixel(int row, int col, const ColorClass &inColor);

    // Initialize image to a single color
    void initializeTo(const ColorClass &inColor);

    // Check if location is valid
    bool isValidLocation(int row, int col) const;

    // Read image from PPM file
    bool readFromPpmFile(const char *fileName);

    // Write image to PPM file
    bool writeToPpmFile(const char *fileName) const;

    // Insert another image with transparency
    bool insertImage(
        const ColorImageClass &sourceImage,
        const RowColumnClass &upperLeft,
        const ColorClass &transparencyColor);
};

#endif

