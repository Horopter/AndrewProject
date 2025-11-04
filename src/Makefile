# Makefile for EECS402 Project 3
# Builds imageMods402.exe from all source files

CXX = g++
CXXFLAGS = -Wall -std=c++98

# Build directory
BUILD_DIR = ../build

# Executable name
EXEC = $(BUILD_DIR)/imageMods402.exe

# Object files
OBJS = $(BUILD_DIR)/ColorClass.o \
       $(BUILD_DIR)/RowColumnClass.o \
       $(BUILD_DIR)/ColorImageClass.o \
       $(BUILD_DIR)/RectangleClass.o \
       $(BUILD_DIR)/PatternClass.o \
       $(BUILD_DIR)/imageMods402.o

# Default target
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

# Individual object file dependencies
$(BUILD_DIR)/ColorClass.o: ColorClass.cpp ColorClass.h
	$(CXX) $(CXXFLAGS) -c ColorClass.cpp -o $(BUILD_DIR)/ColorClass.o

$(BUILD_DIR)/RowColumnClass.o: RowColumnClass.cpp RowColumnClass.h
	$(CXX) $(CXXFLAGS) -c RowColumnClass.cpp -o $(BUILD_DIR)/RowColumnClass.o

$(BUILD_DIR)/ColorImageClass.o: ColorImageClass.cpp ColorImageClass.h \
                ColorClass.h RowColumnClass.h
	$(CXX) $(CXXFLAGS) -c ColorImageClass.cpp -o $(BUILD_DIR)/ColorImageClass.o

$(BUILD_DIR)/RectangleClass.o: RectangleClass.cpp RectangleClass.h \
                ColorImageClass.h ColorClass.h RowColumnClass.h
	$(CXX) $(CXXFLAGS) -c RectangleClass.cpp -o $(BUILD_DIR)/RectangleClass.o

$(BUILD_DIR)/PatternClass.o: PatternClass.cpp PatternClass.h \
                ColorImageClass.h ColorClass.h RowColumnClass.h
	$(CXX) $(CXXFLAGS) -c PatternClass.cpp -o $(BUILD_DIR)/PatternClass.o

$(BUILD_DIR)/imageMods402.o: imageMods402.cpp ColorImageClass.h ColorClass.h \
                RowColumnClass.h RectangleClass.h PatternClass.h
	$(CXX) $(CXXFLAGS) -c imageMods402.cpp -o $(BUILD_DIR)/imageMods402.o

# Clean target
clean:
	rm -f $(OBJS) $(EXEC)

