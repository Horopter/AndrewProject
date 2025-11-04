/*
 * imageMods402.cpp
 * 
 * Programmer: Anjali Aurora
 * Date: November 2025
 * 
 * Purpose: Main program for EECS402 Project 3. Provides a menu-driven
 *          interface for modifying PPM images by drawing rectangles,
 *          patterns, and inserting other images.
 */

#include <iostream>
#include <cstring>
#include "ColorImageClass.h"
#include "ColorClass.h"
#include "RowColumnLocationClass.h"
#include "readPpmFile.h"
#include "writePpmFile.h"
#include "drawRectangle.h"
#include "drawPattern.h"
#include "insertImage.h"
#include "getMenuChoice.h"
using namespace std;

const int MAX_FILENAME_LENGTH = 256;

void displayMainMenu()
{
  cout << "1. Annotate image with rectangle" << endl;
  cout << "2. Annotate image with pattern from file" << endl;
  cout << "3. Insert another image" << endl;
  cout << "4. Write out current image" << endl;
  cout << "5. Exit the program" << endl;
  cout << "Enter int for main menu choice: ";
}

void handleRectangleOption(ColorImageClass &image)
{
  cout << "1. Specify upper left and lower right corners of rectangle"
       << endl;
  cout << "2. Specify upper left corner and dimensions of rectangle"
       << endl;
  cout << "3. Specify extent from center of rectangle" << endl;
  cout << "Enter int for rectangle specification method: ";

  int methodChoice;
  if (!getIntInput(methodChoice))
  {
    cout << "Invalid data entered" << endl;
    return;
  }

  RowColumnLocationClass upperLeft;
  RowColumnLocationClass lowerRight;
  RowColumnLocationClass center;
  int numRows;
  int numCols;
  int halfRows;
  int halfCols;
  ColorClass color;
  bool fill = false;

  if (methodChoice == 1)
  {
    cout << "Enter upper left corner row and column: ";
    int row1, col1;
    if (!getIntInput(row1) || !getIntInput(col1))
    {
      cout << "Invalid data entered" << endl;
      return;
    }
    upperLeft.setRowCol(row1, col1);

    cout << "Enter lower right corner row and column: ";
    int row2, col2;
    if (!getIntInput(row2) || !getIntInput(col2))
    {
      cout << "Invalid data entered" << endl;
      return;
    }
    lowerRight.setRowCol(row2, col2);

    getColorFromMenu(color);

    cout << "1. No" << endl;
    cout << "2. Yes" << endl;
    cout << "Enter int for rectangle fill option: ";
    int fillChoice;
    if (!getIntInput(fillChoice))
    {
      cout << "Invalid data entered" << endl;
      return;
    }
    fill = (fillChoice == 2);

    drawRectangleCorners(image, upperLeft, lowerRight, color, fill);
  }
  else if (methodChoice == 2)
  {
    cout << "Enter upper left corner row and column: ";
    int row, col;
    if (!getIntInput(row) || !getIntInput(col))
    {
      cout << "Invalid data entered" << endl;
      return;
    }
    upperLeft.setRowCol(row, col);

    cout << "Enter int for number of rows: ";
    if (!getIntInput(numRows))
    {
      cout << "Invalid data entered" << endl;
      return;
    }

    cout << "Enter int for number of columns: ";
    if (!getIntInput(numCols))
    {
      cout << "Invalid data entered" << endl;
      return;
    }

    getColorFromMenu(color);

    cout << "1. No" << endl;
    cout << "2. Yes" << endl;
    cout << "Enter int for rectangle fill option: ";
    int fillChoice;
    if (!getIntInput(fillChoice))
    {
      cout << "Invalid data entered" << endl;
      return;
    }
    fill = (fillChoice == 2);

    drawRectangleDimensions(image, upperLeft, numRows, numCols, color, fill);
  }
  else if (methodChoice == 3)
  {
    cout << "Enter rectangle center row and column: ";
    int row, col;
    if (!getIntInput(row) || !getIntInput(col))
    {
      cout << "Invalid data entered" << endl;
      return;
    }
    center.setRowCol(row, col);

    cout << "Enter int for half number of rows: ";
    if (!getIntInput(halfRows))
    {
      cout << "Invalid data entered" << endl;
      return;
    }

    cout << "Enter int for half number of columns: ";
    if (!getIntInput(halfCols))
    {
      cout << "Invalid data entered" << endl;
      return;
    }

    getColorFromMenu(color);

    cout << "1. No" << endl;
    cout << "2. Yes" << endl;
    cout << "Enter int for rectangle fill option: ";
    int fillChoice;
    if (!getIntInput(fillChoice))
    {
      cout << "Invalid data entered" << endl;
      return;
    }
    fill = (fillChoice == 2);

    drawRectangleCenter(image, center, halfRows, halfCols, color, fill);
  }
}

void handlePatternOption(ColorImageClass &image)
{
  char patternFileName[MAX_FILENAME_LENGTH];
  cout << "Enter string for file name containing pattern: ";
  if (!getStringInput(patternFileName, MAX_FILENAME_LENGTH))
  {
    cout << "Invalid data entered" << endl;
    return;
  }

  RowColumnLocationClass upperLeft;
  cout << "Enter upper left corner of pattern row and column: ";
  int row, col;
  if (!getIntInput(row) || !getIntInput(col))
  {
    cout << "Invalid data entered" << endl;
    return;
  }
  upperLeft.setRowCol(row, col);

  ColorClass color;
  getColorFromMenu(color);

  if (!drawPattern(image, patternFileName, upperLeft, color))
  {
    cout << "Error: Unable to open pattern file: " << patternFileName
         << endl;
  }
}

void handleInsertOption(ColorImageClass &image)
{
  char insertFileName[MAX_FILENAME_LENGTH];
  cout << "Enter string for file name of PPM image to insert: ";
  if (!getStringInput(insertFileName, MAX_FILENAME_LENGTH))
  {
    cout << "Invalid data entered" << endl;
    return;
  }

  RowColumnLocationClass upperLeft;
  cout << "Enter upper left corner to insert image row and column: ";
  int row, col;
  if (!getIntInput(row) || !getIntInput(col))
  {
    cout << "Invalid data entered" << endl;
    return;
  }
  upperLeft.setRowCol(row, col);

  ColorClass transparencyColor;
  getColorFromMenu(transparencyColor);

  if (!insertImage(image, insertFileName, upperLeft, transparencyColor))
  {
    cout << "Error: Unable to open image file: " << insertFileName
         << endl;
  }
}

void handleWriteOption(ColorImageClass &image)
{
  char outputFileName[MAX_FILENAME_LENGTH];
  cout << "Enter string for PPM file name to output: ";
  if (!getStringInput(outputFileName, MAX_FILENAME_LENGTH))
  {
    cout << "Invalid data entered" << endl;
    return;
  }

  if (!writePpmFile(outputFileName, image))
  {
    cout << "Error: Unable to write file: " << outputFileName << endl;
  }
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    cout << "Usage: " << argv[0] << " <input_ppm_file>" << endl;
    return 1;
  }

  ColorImageClass image;
  if (!readPpmFile(argv[1], image))
  {
    cout << "Error: Unable to read input file: " << argv[1] << endl;
    return 1;
  }

  int menuChoice = 0;
  while (menuChoice != 5)
  {
    displayMainMenu();
    if (!getIntInput(menuChoice))
    {
      cout << "Invalid data entered" << endl;
      continue;
    }

    if (menuChoice == 1)
    {
      handleRectangleOption(image);
    }
    else if (menuChoice == 2)
    {
      handlePatternOption(image);
    }
    else if (menuChoice == 3)
    {
      handleInsertOption(image);
    }
    else if (menuChoice == 4)
    {
      handleWriteOption(image);
    }
    else if (menuChoice == 5)
    {
      cout << "Thank you for using this program" << endl;
    }
    else
    {
      cout << "Invalid menu option!" << endl;
    }
  }

  return 0;
}

