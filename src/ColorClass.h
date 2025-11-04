/*
 * ColorClass.h
 * 
 * Programmer: Anjali Aurora
 * Date: November 2025
 * 
 * Purpose: Defines the ColorClass which represents a color using
 *          RGB values (red, green, blue components).
 */

#ifndef COLORCLASS_H
#define COLORCLASS_H

class ColorClass
{
  private:
    int red;
    int green;
    int blue;

  public:
    // Default constructor - sets to black
    ColorClass();

    // Constructor with RGB values
    ColorClass(int inRed, int inGreen, int inBlue);

    // Getters
    int getRed() const;
    int getGreen() const;
    int getBlue() const;

    // Setters
    void setRed(int inRed);
    void setGreen(int inGreen);
    void setBlue(int inBlue);

    // Set all RGB values at once
    void setTo(int inRed, int inGreen, int inBlue);

    // Set to predefined colors
    void setToRed();
    void setToGreen();
    void setToBlue();
    void setToBlack();
    void setToWhite();

    // Check if two colors are equal
    bool equals(const ColorClass &rhs) const;
};

#endif

