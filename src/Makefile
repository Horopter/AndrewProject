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
       $(BUILD_DIR)/RowColumnLocationClass.o \
       $(BUILD_DIR)/ColorImageClass.o \
       $(BUILD_DIR)/readPpmFile.o \
       $(BUILD_DIR)/writePpmFile.o \
       $(BUILD_DIR)/drawRectangle.o \
       $(BUILD_DIR)/drawPattern.o \
       $(BUILD_DIR)/insertImage.o \
       $(BUILD_DIR)/getMenuChoice.o \
       $(BUILD_DIR)/imageMods402.o

# Default target
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

# Individual object file dependencies
$(BUILD_DIR)/ColorClass.o: ColorClass.cpp ColorClass.h
	$(CXX) $(CXXFLAGS) -c ColorClass.cpp -o $(BUILD_DIR)/ColorClass.o

$(BUILD_DIR)/RowColumnLocationClass.o: RowColumnLocationClass.cpp RowColumnLocationClass.h
	$(CXX) $(CXXFLAGS) -c RowColumnLocationClass.cpp -o $(BUILD_DIR)/RowColumnLocationClass.o

$(BUILD_DIR)/ColorImageClass.o: ColorImageClass.cpp ColorImageClass.h ColorClass.h
	$(CXX) $(CXXFLAGS) -c ColorImageClass.cpp -o $(BUILD_DIR)/ColorImageClass.o

$(BUILD_DIR)/readPpmFile.o: readPpmFile.cpp readPpmFile.h ColorImageClass.h ColorClass.h
	$(CXX) $(CXXFLAGS) -c readPpmFile.cpp -o $(BUILD_DIR)/readPpmFile.o

$(BUILD_DIR)/writePpmFile.o: writePpmFile.cpp writePpmFile.h ColorImageClass.h ColorClass.h
	$(CXX) $(CXXFLAGS) -c writePpmFile.cpp -o $(BUILD_DIR)/writePpmFile.o

$(BUILD_DIR)/drawRectangle.o: drawRectangle.cpp drawRectangle.h ColorImageClass.h \
                 ColorClass.h RowColumnLocationClass.h
	$(CXX) $(CXXFLAGS) -c drawRectangle.cpp -o $(BUILD_DIR)/drawRectangle.o

$(BUILD_DIR)/drawPattern.o: drawPattern.cpp drawPattern.h ColorImageClass.h \
               ColorClass.h RowColumnLocationClass.h
	$(CXX) $(CXXFLAGS) -c drawPattern.cpp -o $(BUILD_DIR)/drawPattern.o

$(BUILD_DIR)/insertImage.o: insertImage.cpp insertImage.h ColorImageClass.h \
               ColorClass.h RowColumnLocationClass.h readPpmFile.h
	$(CXX) $(CXXFLAGS) -c insertImage.cpp -o $(BUILD_DIR)/insertImage.o

$(BUILD_DIR)/getMenuChoice.o: getMenuChoice.cpp getMenuChoice.h ColorClass.h \
                 RowColumnLocationClass.h
	$(CXX) $(CXXFLAGS) -c getMenuChoice.cpp -o $(BUILD_DIR)/getMenuChoice.o

$(BUILD_DIR)/imageMods402.o: imageMods402.cpp ColorImageClass.h ColorClass.h \
                RowColumnLocationClass.h readPpmFile.h writePpmFile.h \
                drawRectangle.h drawPattern.h insertImage.h \
                getMenuChoice.h
	$(CXX) $(CXXFLAGS) -c imageMods402.cpp -o $(BUILD_DIR)/imageMods402.o

# Clean target
clean:
	rm -f $(OBJS) $(EXEC)
