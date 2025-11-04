/*
 * ColorClass.h
 * 
 * Programmer: Anjali Arora
 * Date: November 2025
 * 
 * Purpose: Defines the ColorClass which represents a color using
 *          RGB values (red, green, blue components).
 */

#ifndef COLORCLASS_H
#define COLORCLASS_H

#include "Constants.h"

class ColorClass
{
  private:
    int redValue;
    int greenValue;
    int blueValue;

  public:
    // Default constructor (sets to black)
    ColorClass();

    // Value constructor with RGB values
    ColorClass(int inRed, int inGreen, int inBlue);

    // Set the color to black
    void setToBlack();

    // Set the color to red
    void setToRed();

    // Set the color to green
    void setToGreen();

    // Set the color to blue
    void setToBlue();

    // Set the color to white
    void setToWhite();

    // Set the color to a specific RGB value
    void setToSpecificColor(int inRed, int inGreen, int inBlue);

    // Get the red component of the color
    int getRed() const;

    // Get the green component of the color
    int getGreen() const;

    // Get the blue component of the color
    int getBlue() const;
};

#endif

