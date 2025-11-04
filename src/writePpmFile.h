/*
 * writePpmFile.h
 * 
 * Programmer: Anjali Aurora
 * Date: November 2025
 * 
 * Purpose: Function prototype for writing a ColorImageClass object
 *          to a PPM file.
 */

#ifndef WRITEPPMFILE_H
#define WRITEPPMFILE_H

#include "ColorImageClass.h"
#include <fstream>

bool writePpmFile(const char *fileName, const ColorImageClass &inImage);

#endif

