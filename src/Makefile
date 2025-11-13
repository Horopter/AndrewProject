# Makefile for EECS402 Project 3
# Builds imageMods402.exe from all source files

CXX = g++
CXXFLAGS = -Wall -std=c++98

# Executable name
EXEC = imageMods402.exe

# Source files
SOURCES = ColorClass.cpp \
          RowColumnClass.cpp \
          ColorImageClass.cpp \
          RectangleClass.cpp \
          PatternClass.cpp \
          imageMods402.cpp

# Header files
HEADERS = ColorClass.h \
          RowColumnClass.h \
          ColorImageClass.h \
          RectangleClass.h \
          PatternClass.h \
          Constants.h

# Default target - compile all sources directly into executable
$(EXEC): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(SOURCES)

# Clean target
clean:
	rm -f $(EXEC)

