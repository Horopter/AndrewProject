/*
 * getMenuChoice.cpp
 * 
 * Programmer: Anjali Aurora
 * Date: November 2025
 * 
 * Purpose: Implements functions for getting user menu choices and
 *          converting color selections to ColorClass objects.
 */

#include "getMenuChoice.h"
#include <iostream>
#include <cstring>
using namespace std;

bool getIntInput(int &value)
{
  cin >> value;
  if (cin.fail())
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

  int colorChoice;
  if (!getIntInput(colorChoice))
  {
    cout << "Invalid data entered" << endl;
    color.setToBlack();
    return;
  }

  if (colorChoice == 1)
  {
    color.setToRed();
  }
  else if (colorChoice == 2)
  {
    color.setToGreen();
  }
  else if (colorChoice == 3)
  {
    color.setToBlue();
  }
  else if (colorChoice == 4)
  {
    color.setToBlack();
  }
  else if (colorChoice == 5)
  {
    color.setToWhite();
  }
  else
  {
    color.setToBlack();
  }
}

void getLocationInput(RowColumnLocationClass &location)
{
  cout << "Enter row and column: ";
  int row;
  int col;
  if (!getIntInput(row) || !getIntInput(col))
  {
    cout << "Invalid data entered" << endl;
    location.setRowCol(0, 0);
    return;
  }
  location.setRowCol(row, col);
}

