/*
 * imageMods402.cpp
 * 
 * Programmer: Anjali Arora
 * Date: November 2025
 * 
 * Purpose: Main program for EECS402 Project 3. Provides a menu-driven
 *          interface for modifying PPM images.
 */

#include <iostream>
#include <cstring>
#include "ColorImageClass.h"
#include "ColorClass.h"
#include "RowColumnClass.h"
#include "RectangleClass.h"
#include "PatternClass.h"
using namespace std;

const int MAX_FILENAME_LENGTH = 256;

bool getIntInput(int &value)
{
  cin >> value;
  if (cin.fail() || cin.eof())
  {
    cin.clear();
    cin.ignore(10000, '\n');
    return false;
  }
  return true;
}

bool getStringInput(char *str, int maxLength)
{
  cin >> str;
  if (cin.fail())
  {
    cin.clear();
    cin.ignore(10000, '\n');
    return false;
  }
  return true;
}

void getColorFromMenu(ColorClass &color)
{
  cout << "1. Red" << endl;
  cout << "2. Green" << endl;
  cout << "3. Blue" << endl;
  cout << "4. Black" << endl;
  cout << "5. White" << endl;
  cout << "Enter int for color choice: ";
  int choice;
  if (!getIntInput(choice))
  {
    choice = 1;
  }

  if (choice == 1)
  {
    color.setToRed();
  }
  else if (choice == 2)
  {
    color.setToGreen();
  }
  else if (choice == 3)
  {
    color.setToBlue();
  }
  else if (choice == 4)
  {
    color.setToBlack();
  }
  else if (choice == 5)
  {
    color.setToWhite();
  }
  else
  {
    color.setToRed();
  }
}

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

  if (methodChoice < 1 || methodChoice > 3)
  {
    cout << "Invalid menu option!" << endl;
    return;
  }

  RowColumnClass upperLeft;
  RowColumnClass lowerRight;
  RowColumnClass center;
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
    if (!getIntInput(row1))
    {
      cout << "Invalid data entered" << endl;
      return;
    }
    if (!getIntInput(col1))
    {
      cout << "Invalid data entered" << endl;
      return;
    }
    upperLeft.setRowCol(row1, col1);

    cout << "Enter lower right corner row and column: ";
    int row2, col2;
    if (!getIntInput(row2))
    {
      cout << "Invalid data entered" << endl;
      return;
    }
    if (!getIntInput(col2))
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

    RectangleClass rectangle(upperLeft, lowerRight, color, fill);
    rectangle.drawOntoImage(image);
  }
  else if (methodChoice == 2)
  {
    cout << "Enter upper left corner row and column: ";
    int row, col;
    if (!getIntInput(row))
    {
      cout << "Invalid data entered" << endl;
      return;
    }
    if (!getIntInput(col))
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

    RowColumnClass lowerRight(upperLeft.getRow() + numRows - 1,
                              upperLeft.getCol() + numCols - 1);
    RectangleClass rectangle(upperLeft, lowerRight, color, fill);
    rectangle.drawOntoImage(image);
  }
  else if (methodChoice == 3)
  {
    cout << "Enter rectangle center row and column: ";
    int row, col;
    if (!getIntInput(row))
    {
      cout << "Invalid data entered" << endl;
      return;
    }
    if (!getIntInput(col))
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

    RowColumnClass upperLeft(center.getRow() - halfRows,
                            center.getCol() - halfCols);
    RowColumnClass lowerRight(center.getRow() + halfRows,
                              center.getCol() + halfCols);
    RectangleClass rectangle(upperLeft, lowerRight, color, fill);
    rectangle.drawOntoImage(image);
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

  RowColumnClass upperLeft;
  cout << "Enter upper left corner of pattern row and column: ";
  int row, col;
  if (!getIntInput(row))
  {
    cout << "Invalid data entered" << endl;
    return;
  }
  if (!getIntInput(col))
  {
    cout << "Invalid data entered" << endl;
    return;
  }
  upperLeft.setRowCol(row, col);

  ColorClass color;
  getColorFromMenu(color);

  PatternClass pattern;
  if (!pattern.readPatternFromFile(patternFileName))
  {
    return;
  }

  pattern.drawOntoImage(image, upperLeft, color);
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

  RowColumnClass upperLeft;
  cout << "Enter upper left corner to insert image row and column: ";
  int row, col;
  if (!getIntInput(row))
  {
    cout << "Invalid data entered" << endl;
    return;
  }
  if (!getIntInput(col))
  {
    cout << "Invalid data entered" << endl;
    return;
  }
  upperLeft.setRowCol(row, col);

  ColorClass transparencyColor;
  cout << "1. Red" << endl;
  cout << "2. Green" << endl;
  cout << "3. Blue" << endl;
  cout << "4. Black" << endl;
  cout << "5. White" << endl;
  cout << "Enter int for transparecy color: ";
  int choice;
  if (!getIntInput(choice))
  {
    choice = 1;
  }

  if (choice == 1)
  {
    transparencyColor.setToRed();
  }
  else if (choice == 2)
  {
    transparencyColor.setToGreen();
  }
  else if (choice == 3)
  {
    transparencyColor.setToBlue();
  }
  else if (choice == 4)
  {
    transparencyColor.setToBlack();
  }
  else if (choice == 5)
  {
    transparencyColor.setToWhite();
  }
  else
  {
    transparencyColor.setToRed();
  }

  ColorImageClass sourceImage;
  if (!sourceImage.readFromPpmFile(insertFileName))
  {
    cout << "Error: Unable to open image file: " << insertFileName 
         << endl;
    return;
  }

  image.insertImage(sourceImage, upperLeft, transparencyColor);
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

  if (!image.writeToPpmFile(outputFileName))
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
  if (!image.readFromPpmFile(argv[1]))
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
      if (cin.eof())
      {
        break;
      }
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

