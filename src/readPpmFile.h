/*
 * readPpmFile.h
 * 
 * Programmer: Anjali Aurora
 * Date: November 2025
 * 
 * Purpose: Function prototype for reading a PPM file and creating
 *          a ColorImageClass object.
 */

#ifndef READPPMFILE_H
#define READPPMFILE_H

#include "ColorImageClass.h"
#include <fstream>

bool readPpmFile(const char *fileName, ColorImageClass &outImage);

#endif

