/*
 * getMenuChoice.h
 * 
 * Programmer: Anjali Aurora
 * Date: November 2025
 * 
 * Purpose: Function prototypes for getting user menu choices and
 *          converting color selections to ColorClass objects.
 */

#ifndef GETMENUCHOICE_H
#define GETMENUCHOICE_H

#include "ColorClass.h"
#include "RowColumnLocationClass.h"

bool getIntInput(int &value);
bool getStringInput(char *str, int maxLength);
void getColorFromMenu(ColorClass &color);
void getLocationInput(RowColumnLocationClass &location);

#endif

