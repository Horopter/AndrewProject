/*
 * PatternClass.h
 * 
 * Programmer: Anjali Arora
 * Date: November 2025
 * 
 * Purpose: Defines the PatternClass which represents a pattern read
 *          from a file that can be drawn onto an image.
 */

#ifndef PATTERNCLASS_H
#define PATTERNCLASS_H

#include "ColorImageClass.h"
#include "ColorClass.h"
#include "RowColumnClass.h"

class PatternClass
{
  private:
    int patternRows;
    int patternCols;
    int **patternData;

    void allocatePatternData(int inRows, int inCols);
    void deallocatePatternData();

  public:
    PatternClass();
    ~PatternClass();
    PatternClass(const PatternClass &rhs);
    PatternClass& operator=(const PatternClass &rhs);

    bool readPatternFromFile(const char *fileName);
    bool drawOntoImage(
        ColorImageClass &image,
        const RowColumnClass &upperLeft,
        const ColorClass &color) const;

    int getNumRows() const;
    int getNumCols() const;
};

#endif

