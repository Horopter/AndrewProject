/*
 * Constants.h
 *
 * Programmer: Anjali Arora
 * Date: November 2025
 *
 * Purpose: Centralized constants used across the project.
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

// Image and color ranges
const int MIN_COLOR_VALUE = 0;
const int MAX_COLOR_VALUE = 255;
const int MIN_IMAGE_DIM = 1;
const int MAX_IMAGE_DIM = 2000;

// Main menu choices
const int MENU_CHOICE_RECTANGLE = 1;
const int MENU_CHOICE_PATTERN   = 2;
const int MENU_CHOICE_INSERT    = 3;
const int MENU_CHOICE_OUTPUT    = 4;
const int MENU_CHOICE_EXIT      = 5;

// Rectangle specification
const int RECT_SPEC_UL_LR         = 1;
const int RECT_SPEC_UL_SIZE       = 2;
const int RECT_SPEC_CENTER_EXTENT = 3;

// Rectangle input bounds
const int MIN_RECT_ROWS   = 1;
const int MIN_RECT_COLS   = 1;
const int HALF_EXTENT_MIN = 0;

// Rectangle fill option
const int RECT_FILL_NO  = 1;
const int RECT_FILL_YES = 2;

// Color menu choices
const int COLOR_CHOICE_RED   = 1;
const int COLOR_CHOICE_GREEN = 2;
const int COLOR_CHOICE_BLUE  = 3;
const int COLOR_CHOICE_BLACK = 4;
const int COLOR_CHOICE_WHITE = 5;

// Input flushing
const int INPUT_FLUSH_COUNT = 10000;

// Exit codes
const int EXIT_BAD_ARG    = 2;
const int EXIT_FILE_ERROR = 3;

#endif


