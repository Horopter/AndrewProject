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
#include "Constants.h"
#include "ColorClass.h"
#include "RowColumnClass.h"
#include "RectangleClass.h"
#include "PatternClass.h"
using namespace std;

const int MAX_FILENAME_LENGTH = 256;

// Function prototypes
bool getIntInput(int &value);
bool getStringInput(char *str, int maxLength);
void displayMenuOption(int number, const string &text);
void displayColorMenu();
bool setColorFromChoice(ColorClass &color, int choice);
void getColorFromMenu(ColorClass &color, 
                      const string &prompt = PROMPT_COLOR_CHOICE);
bool getRowColumnInput(RowColumnClass &position, 
                       const string &prompt);
bool getFillOption(bool &fill);
void displayMainMenu();
void handleRectangleOption(ColorImageClass &image);
void handlePatternOption(ColorImageClass &image);
void handleInsertOption(ColorImageClass &image);
void handleWriteOption(ColorImageClass &image);

#ifdef ANDREW_TEST
#include "andrewTest.h"
#else
int main(int argc, char *argv[])
{
  // Expect exactly one input file argument
  if (argc != REQUIRED_ARGC)
  {
    cout << MSG_USAGE << argv[ARGC_PROGRAM_NAME_INDEX] 
         << " <input_ppm_file>" << endl;
    return EXIT_BAD_ARG;
  }

  ColorImageClass image;
  if (!image.readFromPpmFile(argv[ARGC_INPUT_FILE_INDEX]))
  {
    cout << ERROR_UNABLE_TO_READ_INPUT 
         << argv[ARGC_INPUT_FILE_INDEX] << endl;
    return EXIT_FILE_ERROR;
  }

  // Main menu loop until user selects Exit or EOF
  int menuChoice = EXIT_SUCCESS_CODE;
  while (menuChoice != MENU_CHOICE_EXIT)
  {
    displayMainMenu();
    if (!getIntInput(menuChoice))
    {
      cout << ERROR_INVALID_DATA << endl;
      if (cin.eof())
      {
        break;
      }
      continue;
    }

    if (menuChoice == MENU_CHOICE_RECTANGLE)
    {
      handleRectangleOption(image);
    }
    else if (menuChoice == MENU_CHOICE_PATTERN)
    {
      handlePatternOption(image);
    }
    else if (menuChoice == MENU_CHOICE_INSERT)
    {
      handleInsertOption(image);
    }
    else if (menuChoice == MENU_CHOICE_OUTPUT)
    {
      handleWriteOption(image);
    }
    else if (menuChoice == MENU_CHOICE_EXIT)
    {
      cout << MSG_THANK_YOU << endl;
    }
    else
    {
      cout << ERROR_INVALID_MENU_OPTION << endl;
    }
  }

  return EXIT_SUCCESS_CODE;
}
#endif

// Function implementations
bool getIntInput(int &value)
{
  // Read an int; handle fail/EOF and clear bad input
  cin >> value;
  if (cin.fail() || cin.eof())
  {
    cin.clear();
    cin.ignore(INPUT_FLUSH_COUNT, '\n');
    return false;
  }
  return true;
}

bool getStringInput(char *str, int maxLength)
{
  // Read a token string; clear bad input on fail
  cin >> str;
  if (cin.fail())
  {
    cin.clear();
    cin.ignore(INPUT_FLUSH_COUNT, '\n');
    return false;
  }
  return true;
}

void displayMenuOption(int number, const string &text)
{
  // Display a menu option in the format: "NUMBER. TEXT"
  cout << number << ". " << text << endl;
}

void displayColorMenu()
{
  // Display the color selection menu
  displayMenuOption(COLOR_CHOICE_RED, COLOR_NAME_RED);
  displayMenuOption(COLOR_CHOICE_GREEN, COLOR_NAME_GREEN);
  displayMenuOption(COLOR_CHOICE_BLUE, COLOR_NAME_BLUE);
  displayMenuOption(COLOR_CHOICE_BLACK, COLOR_NAME_BLACK);
  displayMenuOption(COLOR_CHOICE_WHITE, COLOR_NAME_WHITE);
}

bool setColorFromChoice(ColorClass &color, int choice)
{
  // Set color based on choice, return true if valid choice
  if (choice == COLOR_CHOICE_RED)
  {
    color.setToRed();
    return true;
  }
  else if (choice == COLOR_CHOICE_GREEN)
  {
    color.setToGreen();
    return true;
  }
  else if (choice == COLOR_CHOICE_BLUE)
  {
    color.setToBlue();
    return true;
  }
  else if (choice == COLOR_CHOICE_BLACK)
  {
    color.setToBlack();
    return true;
  }
  else if (choice == COLOR_CHOICE_WHITE)
  {
    color.setToWhite();
    return true;
  }
  return false;
}

void getColorFromMenu(ColorClass &color, const string &prompt)
{
  // Show color menu and set color based on user choice
  int choice;
  bool validChoice = false;
  
  while (!validChoice)
  {
    displayColorMenu();
    cout << prompt;
    
    if (!getIntInput(choice))
    {
      if (cin.eof())
      {
        // EOF encountered, default to red and return
        color.setToRed();
        return;
      }
      cout << ERROR_INVALID_DATA << endl;
      continue;
    }
    
    if (setColorFromChoice(color, choice))
    {
      validChoice = true;
    }
    else
    {
      cout << ERROR_INVALID_MENU_OPTION << endl;
    }
  }
}

bool getRowColumnInput(RowColumnClass &position, const string &prompt)
{
  // Get row and column input with EOF handling, return false on EOF
  int row, col;
  bool validInput = false;
  
  while (!validInput)
  {
    cout << prompt;
    if (!getIntInput(row))
    {
      if (cin.eof())
      {
        return false;
      }
      cout << ERROR_INVALID_DATA << endl;
      continue;
    }
    if (!getIntInput(col))
    {
      if (cin.eof())
      {
        return false;
      }
      cout << ERROR_INVALID_DATA << endl;
      continue;
    }
    validInput = true;
  }
  position.setRowCol(row, col);
  return true;
}

bool getFillOption(bool &fill)
{
  // Get fill option from user, return false on error/EOF
  displayMenuOption(RECT_FILL_NO, FILL_OPTION_NO);
  displayMenuOption(RECT_FILL_YES, FILL_OPTION_YES);
  cout << PROMPT_RECTANGLE_FILL;
  int fillChoice;
  if (!getIntInput(fillChoice))
  {
    return false;
  }
  fill = (fillChoice == RECT_FILL_YES);
  return true;
}

void displayMainMenu()
{
  // Print the main menu every loop
  displayMenuOption(MENU_CHOICE_RECTANGLE, MENU_OPTION_RECTANGLE);
  displayMenuOption(MENU_CHOICE_PATTERN, MENU_OPTION_PATTERN);
  displayMenuOption(MENU_CHOICE_INSERT, MENU_OPTION_INSERT);
  displayMenuOption(MENU_CHOICE_OUTPUT, MENU_OPTION_OUTPUT);
  displayMenuOption(MENU_CHOICE_EXIT, MENU_OPTION_EXIT);
  cout << PROMPT_MAIN_MENU;
}

void handleRectangleOption(ColorImageClass &image)
{
  // Ask how to specify rectangle
  displayMenuOption(RECT_SPEC_UL_LR, RECT_SPEC_METHOD_UL_LR);
  displayMenuOption(RECT_SPEC_UL_SIZE, RECT_SPEC_METHOD_UL_SIZE);
  displayMenuOption(RECT_SPEC_CENTER_EXTENT, 
                    RECT_SPEC_METHOD_CENTER_EXTENT);
  cout << PROMPT_RECT_SPEC_METHOD;

  int methodChoice;
  if (!getIntInput(methodChoice))
  {
    cout << ERROR_INVALID_DATA << endl;
    return;
  }

  if (methodChoice < RECT_SPEC_UL_LR ||
      methodChoice > RECT_SPEC_CENTER_EXTENT)
  {
    cout << ERROR_INVALID_MENU_OPTION << endl;
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

  if (methodChoice == RECT_SPEC_UL_LR)
  {
    // Method 1: two corners
    cout << PROMPT_UPPER_LEFT_CORNER;
    int row1, col1;
    if (!getIntInput(row1))
    {
      cout << ERROR_INVALID_DATA << endl;
      return;
    }
    if (!getIntInput(col1))
    {
      cout << ERROR_INVALID_DATA << endl;
      return;
    }
    upperLeft.setRowCol(row1, col1);

    cout << PROMPT_LOWER_RIGHT_CORNER;
    int row2, col2;
    if (!getIntInput(row2))
    {
      cout << ERROR_INVALID_DATA << endl;
      return;
    }
    if (!getIntInput(col2))
    {
      cout << ERROR_INVALID_DATA << endl;
      return;
    }
    lowerRight.setRowCol(row2, col2);

    // Choose color and fill option
    getColorFromMenu(color, PROMPT_RECTANGLE_COLOR);

    if (!getFillOption(fill))
    {
      cout << ERROR_INVALID_DATA << endl;
      return;
    }

    RectangleClass rectangle(upperLeft, lowerRight, color, fill);
    rectangle.drawOntoImage(image);
  }
  else if (methodChoice == RECT_SPEC_UL_SIZE)
  {
    // Method 2: corner + dimensions
    cout << PROMPT_UPPER_LEFT_CORNER;
    int row, col;
    if (!getIntInput(row))
    {
      cout << ERROR_INVALID_DATA << endl;
      return;
    }
    if (!getIntInput(col))
    {
      cout << ERROR_INVALID_DATA << endl;
      return;
    }
    upperLeft.setRowCol(row, col);

    cout << PROMPT_NUMBER_OF_ROWS;
    if (!getIntInput(numRows))
    {
      cout << ERROR_INVALID_DATA << endl;
      return;
    }

    cout << PROMPT_NUMBER_OF_COLUMNS;
    if (!getIntInput(numCols))
    {
      cout << ERROR_INVALID_DATA << endl;
      return;
    }

    // Choose color and fill option
    getColorFromMenu(color, PROMPT_RECTANGLE_COLOR);

    if (!getFillOption(fill))
    {
      cout << ERROR_INVALID_DATA << endl;
      return;
    }

    // Use RectangleClass method to properly calculate dimensions
    RectangleClass rectangle;
    rectangle.setUsingDimensions(upperLeft, numRows, numCols);
    rectangle.setColor(color);
    rectangle.setFill(fill);
    rectangle.drawOntoImage(image);
  }
  else if (methodChoice == RECT_SPEC_CENTER_EXTENT)
  {
    // Method 3: center + extents
    cout << PROMPT_RECTANGLE_CENTER;
    int row, col;
    if (!getIntInput(row))
    {
      cout << ERROR_INVALID_DATA << endl;
      return;
    }
    if (!getIntInput(col))
    {
      cout << ERROR_INVALID_DATA << endl;
      return;
    }
    center.setRowCol(row, col);

    cout << PROMPT_HALF_NUMBER_OF_ROWS;
    if (!getIntInput(halfRows))
    {
      cout << ERROR_INVALID_DATA << endl;
      return;
    }

    cout << PROMPT_HALF_NUMBER_OF_COLUMNS;
    if (!getIntInput(halfCols))
    {
      cout << ERROR_INVALID_DATA << endl;
      return;
    }

    // Choose color and fill option
    getColorFromMenu(color, PROMPT_RECTANGLE_COLOR);

    if (!getFillOption(fill))
    {
      cout << ERROR_INVALID_DATA << endl;
      return;
    }

    // Use RectangleClass method to properly calculate center-based rectangle
    RectangleClass rectangle;
    rectangle.setUsingCenter(center, halfRows, halfCols);
    rectangle.setColor(color);
    rectangle.setFill(fill);
    rectangle.drawOntoImage(image);
  }
}

void handlePatternOption(ColorImageClass &image)
{
  // Read pattern file name
  char patternFileName[MAX_FILENAME_LENGTH];
  cout << PROMPT_PATTERN_FILE;
  if (!getStringInput(patternFileName, MAX_FILENAME_LENGTH))
  {
    cout << ERROR_INVALID_DATA << endl;
    return;
  }

  // Read placement and color
  RowColumnClass upperLeft;
  if (!getRowColumnInput(upperLeft, PROMPT_PATTERN_CORNER))
  {
    return;
  }

  ColorClass color;
  getColorFromMenu(color, PROMPT_PATTERN_COLOR);

  PatternClass pattern;
  if (!pattern.readPatternFromFile(patternFileName))
  {
    return;
  }

  pattern.drawOntoImage(image, upperLeft, color);
}

void handleInsertOption(ColorImageClass &image)
{
  // Read source image file name
  char insertFileName[MAX_FILENAME_LENGTH];
  cout << PROMPT_INSERT_FILE;
  if (!getStringInput(insertFileName, MAX_FILENAME_LENGTH))
  {
    cout << ERROR_INVALID_DATA << endl;
    return;
  }

  // Read placement
  RowColumnClass upperLeft;
  if (!getRowColumnInput(upperLeft, PROMPT_INSERT_CORNER))
  {
    return;
  }

  // Pick transparency color for overlay
  ColorClass transparencyColor;
  getColorFromMenu(transparencyColor, PROMPT_TRANSPARENCY_COLOR);

  ColorImageClass sourceImage;
  if (!sourceImage.readFromPpmFile(insertFileName))
  {
    cout << ERROR_UNABLE_TO_OPEN_IMAGE << insertFileName << endl;
    return;
  }

  image.insertImage(sourceImage, upperLeft, transparencyColor);
}

void handleWriteOption(ColorImageClass &image)
{
  // Ask for output file and write the image
  char outputFileName[MAX_FILENAME_LENGTH];
  cout << PROMPT_OUTPUT_FILE;
  if (!getStringInput(outputFileName, MAX_FILENAME_LENGTH))
  {
    cout << ERROR_INVALID_DATA << endl;
    return;
  }

  if (!image.writeToPpmFile(outputFileName))
  {
    cout << ERROR_UNABLE_TO_WRITE_FILE << outputFileName << endl;
  }
}
