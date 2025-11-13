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

#include <string>
using namespace std;

// Image and color ranges
const int MIN_COLOR_VALUE = 0;
const int MAX_COLOR_VALUE = 255;
const int MIN_IMAGE_DIM = 1;
const int MAX_IMAGE_DIM = 2000;
const int MIN_COORDINATE = 0;
const int MIN_MAX_COLOR_VALUE = 1;

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
const int EXIT_SUCCESS_CODE = 0;
const int EXIT_BAD_ARG    = 2;
const int EXIT_FILE_ERROR = 3;

// Command line arguments
const int REQUIRED_ARGC = 2;
const int ARGC_PROGRAM_NAME_INDEX = 0;
const int ARGC_INPUT_FILE_INDEX = 1;

// Array index adjustments
const int ARRAY_INDEX_OFFSET = 1;

// String constants
// Menu option strings
const string MENU_OPTION_RECTANGLE = 
    "Annotate image with rectangle";
const string MENU_OPTION_PATTERN = 
    "Annotate image with pattern from file";
const string MENU_OPTION_INSERT = "Insert another image";
const string MENU_OPTION_OUTPUT = "Write out current image";
const string MENU_OPTION_EXIT = "Exit the program";

// Rectangle specification method strings
const string RECT_SPEC_METHOD_UL_LR = 
    "Specify upper left and lower right corners of rectangle";
const string RECT_SPEC_METHOD_UL_SIZE = 
    "Specify upper left corner and dimensions of rectangle";
const string RECT_SPEC_METHOD_CENTER_EXTENT = 
    "Specify extent from center of rectangle";

// Color names
const string COLOR_NAME_RED = "Red";
const string COLOR_NAME_GREEN = "Green";
const string COLOR_NAME_BLUE = "Blue";
const string COLOR_NAME_BLACK = "Black";
const string COLOR_NAME_WHITE = "White";

// Fill option strings
const string FILL_OPTION_NO = "No";
const string FILL_OPTION_YES = "Yes";

// Prompt strings
const string PROMPT_MAIN_MENU = "Enter int for main menu choice: ";
const string PROMPT_RECT_SPEC_METHOD = 
    "Enter int for rectangle specification method: ";
const string PROMPT_UPPER_LEFT_CORNER = 
    "Enter upper left corner row and column: ";
const string PROMPT_LOWER_RIGHT_CORNER = 
    "Enter lower right corner row and column: ";
const string PROMPT_RECTANGLE_COLOR = 
    "Enter int for rectangle color: ";
const string PROMPT_RECTANGLE_FILL = 
    "Enter int for rectangle fill option: ";
const string PROMPT_NUMBER_OF_ROWS = "Enter int for number of rows: ";
const string PROMPT_NUMBER_OF_COLUMNS = 
    "Enter int for number of columns: ";
const string PROMPT_RECTANGLE_CENTER = 
    "Enter rectangle center row and column: ";
const string PROMPT_HALF_NUMBER_OF_ROWS = 
    "Enter int for half number of rows: ";
const string PROMPT_HALF_NUMBER_OF_COLUMNS = 
    "Enter int for half number of columns: ";
const string PROMPT_PATTERN_FILE = 
    "Enter string for file name containing pattern: ";
const string PROMPT_PATTERN_CORNER = 
    "Enter upper left corner of pattern row and column: ";
const string PROMPT_PATTERN_COLOR = "Enter int for pattern color: ";
const string PROMPT_INSERT_FILE = 
    "Enter string for file name of PPM image to insert: ";
const string PROMPT_INSERT_CORNER = 
    "Enter upper left corner to insert image row and column: ";
const string PROMPT_TRANSPARENCY_COLOR = 
    "Enter int for transparecy color: ";
const string PROMPT_OUTPUT_FILE = 
    "Enter string for PPM file name to output: ";
const string PROMPT_COLOR_CHOICE = "Enter int for color choice: ";

// Error messages
const string ERROR_INVALID_DATA = "Invalid data entered";
const string ERROR_INVALID_MENU_OPTION = "Invalid menu option!";
const string ERROR_UNABLE_TO_READ_INPUT = 
    "Error: Unable to read input file: ";
const string ERROR_UNABLE_TO_OPEN_PPM = 
    "Error: Unable to open PPM file: ";
const string ERROR_INVALID_PPM_MAGIC = 
    "Error: Invalid PPM magic number in file: ";
const string ERROR_INVALID_IMAGE_DIMENSIONS = 
    "Error: Invalid image dimensions or max color value in file: ";
const string ERROR_INVALID_PIXEL_DATA = 
    "Error: Invalid pixel data in file: ";
const string ERROR_EXTRA_DATA = "Error: Extra data found in file: ";
const string ERROR_UNABLE_TO_CREATE_PPM = 
    "Error: Unable to create PPM file: ";
const string ERROR_UNABLE_TO_WRITE_PIXEL = 
    "Error: Unable to write pixel data to file: ";
const string ERROR_UNABLE_TO_OPEN_PATTERN = 
    "Error: Unable to open pattern file: ";
const string ERROR_INVALID_PATTERN_DIMENSIONS = 
    "Error: Invalid pattern dimensions in file: ";
const string ERROR_INVALID_PATTERN_DATA = 
    "Error: Invalid pattern data in file: ";
const string ERROR_UNABLE_TO_OPEN_IMAGE = 
    "Error: Unable to open image file: ";
const string ERROR_UNABLE_TO_WRITE_FILE = 
    "Error: Unable to write file: ";

// Other messages
const string MSG_USAGE = "Usage: ";
const string MSG_THANK_YOU = "Thank you for using this program";

// PPM file format
const string PPM_MAGIC_NUMBER = "P3";

#endif


