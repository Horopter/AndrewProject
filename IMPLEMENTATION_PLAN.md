# Project 3 Implementation Plan

## Project Structure

### Classes Needed:
1. **ColorClass** - Represents RGB color (from previous project)
2. **RowColumnLocationClass** - Represents row/column position (from previous project)
3. **ColorImageClass** - Main image class with dynamic allocation

### File Organization:
- `ColorClass.h` / `ColorClass.cpp` - Color representation
- `RowColumnLocationClass.h` / `RowColumnLocationClass.cpp` - Location
- `ColorImageClass.h` / `ColorImageClass.cpp` - Image with dynamic pixels
- `readPpmFile.h` / `readPpmFile.cpp` - Function to read PPM file
- `writePpmFile.h` / `writePpmFile.cpp` - Function to write PPM file
- `drawRectangle.h` / `drawRectangle.cpp` - Rectangle drawing functions
- `drawPattern.h` / `drawPattern.cpp` - Pattern drawing function
- `insertImage.h` / `insertImage.cpp` - Image insertion function
- `getMenuChoice.h` / `getMenuChoice.cpp` - Menu input functions
- `imageMods402.cpp` - Main program

### Implementation Details:

#### ColorClass:
- Red, Green, Blue components (0-255)
- Constructor, getters, setters
- Named colors: Red, Green, Blue, Black, White

#### RowColumnLocationClass:
- Row and Column (integers)
- Constructor, getters, setters

#### ColorImageClass:
- Width, Height (integers)
- Max color value (integer)
- 2D array of ColorClass (dynamically allocated)
- Constructor, destructor, copy constructor, assignment operator
- Get/set pixel color at location

#### Functions:
1. **readPpmFile**: Read PPM file, create ColorImageClass
2. **writePpmFile**: Write ColorImageClass to PPM file
3. **drawRectangle**: Three methods (corners, upper-left+dimensions, center+extent)
4. **drawPattern**: Read pattern file, draw pattern at location
5. **insertImage**: Read another PPM, insert at location with transparency
6. **getMenuChoice**: Get user menu selections

### Main Program Flow:
1. Read input PPM file from command line
2. Display main menu loop
3. Process user choices:
   - Option 1: Draw rectangle (with sub-menu for method)
   - Option 2: Draw pattern from file
   - Option 3: Insert another image
   - Option 4: Write image to file
   - Option 5: Exit
4. Handle errors appropriately

### Error Handling:
- Invalid menu choices
- Invalid file names
- Invalid data entry (non-integers)
- Stream errors

