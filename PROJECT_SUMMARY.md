# EECS402 Project 3 Summary

## 1. Submission Instructions (402_submissionInfo.pdf)

### Compilation Requirements:
- **Compiler**: Must use `g++` compiler
- **Required flags**: `-Wall -std=c++98` must always be included
- **Example**: `g++ -Wall -std=c++98 project1.cpp -o project1.exe`

### Valgrind Requirements:
- **Tool**: Must use `valgrind` for memory checking
- **Required flag**: `--leak-check=full` must always be used
- **Example**: `valgrind --leak-check=full ./project1.exe`

### Submission Process:
- **Method**: Email submission only (NOT Canvas or direct emails)
- **Script file**: Must generate a "typescript" file using Linux `script` command
- **Process**: 
  1. Run `script` command
  2. Build project with required g++ flags
  3. Run program in valgrind with required flags
  4. Type `exit` to stop recording
  5. File named "typescript" will be created
- **Important**: Verify all files are attached and accepted by checking submission response email

### Typescript File:
- Records all keystrokes and console output
- Backspace characters may appear but are acceptable
- Should be reasonably small in size
- Must demonstrate building and running valgrind

---

## 2. Project 3 Specifications (p3specs.pdf)

### Overview:
- **Project Focus**: Image manipulation and modification
- **Real-world applications**: Image sharpening, red-eye removal, image markup, conversation bubbles
- **Learning objectives**: Dynamic allocation, file I/O, multi-file organization, stream error handling

### Due Date:
- **Due**: Tuesday, November 4, 2025 at 4:30pm
- **Early submission**: Bonus points available (per course syllabus)

### Required Submission Files:
- All `.h` header files
- All `.cpp` source files
- **Main file**: Must be named exactly `imageMods402.cpp`
- **Makefile**: Must build executable named exactly `imageMods402.exe` using `make` command
- **Makefile target**: Must have `clean` target to remove `.o` files and executable
- **Typescript file**: Shows building and running valgrind with no memory leaks
- **Submission method**: Attach each file separately (do NOT zip/tar/compress)

### PPM Image Format Background:
- **Format**: ASCII text file (not binary)
- **Magic number**: Must start with "P3" (invalid if not)
- **File structure**:
  1. Magic number: "P3"
  2. Width (integer) - number of columns
  3. Height (integer) - number of rows
  4. Maximum color value (integer)
  5. Pixel data: RGB values (3 integers per pixel)

### Project Requirements:
- Uses concepts from previous project (Color, Color Image, Row/Column Location classes)
- Focus on dynamic array allocation
- File input/output operations
- Multi-file organization
- Stream error detection and handling

---

## 3. Style and Design Requirements (StyleDesignRequirements_proj3.pdf)

### Variables:
- **Naming**: Start with lowercase letter
- **Descriptive names**: Required (exception: standard loop variables 'i', 'j', 'k')
- **Naming convention**: Not a verb (sounds like a noun, not function)
- **Preferred style**: camelCase for multi-word names (e.g., `numQuizzes`, `numberOfValues`)
- **Consistency**: Required in naming scheme (case, underscores, etc.)

### Constants:
- **Naming**: ALL UPPERCASE letters
- **Word separation**: Underscores (e.g., `NUMBER_OF_EXAMS`)

### Functions:
- **Naming**: Start with lowercase letter
- **Descriptive names**: Required
- **Naming convention**: Verb form (sounds like functionality, e.g., `computeAverage` not `average`)
- **Preferred style**: camelCase for multi-word names
- **Consistency**: Required in naming scheme

### Code Formatting:
- **Curly braces**: Consistent placement (same style throughout)
- **Preferred**: Use curly braces even for single statements after `if` or loops
- **Line length**: Maximum 80 characters (required)
- **Tabs**: NOT allowed in source code
- **Indentation**: Consistent number of spaces throughout entire codebase
- **Block indentation**: Every code block within curly braces must be indented

### Comments/Documentation:
- **Header block**: Required on every source file
  - Programmer's name
  - Approximate date written
  - Brief statement of purpose
- **Inline comments**: Required for non-obvious code sections

### Program Organization:
- **Loops**: Avoid `while(true)` loops with `break` - use proper loop conditions
- **Flow control**: Avoid `break` and `continue` in loops
- **Language restrictions**: Only use topics covered in class (no advanced features)
- **Function organization**:
  - Each global function prototype in its own `.h` file
  - Each global function implementation in its own `.cpp` file
  - Exception: Overloaded functions with same name grouped together
- **Class organization**:
  - Each class defined in its own `.h` file
  - Class methods prototyped in `.h` file
  - Exception: Very simple functions (1-4 lines) can be in `.h` file
  - Class method implementations in single `.cpp` file for that class

### Arrays:
- **Static arrays**: Size must be specified using literal values or named constants

### Classes and Objects:
- **Class naming**: Start with uppercase, use camelCase (e.g., `QuizClass`, `ModeOfTransportationClass`)
- **Object naming**: Follow variable naming rules (lowercase start, camelCase)
- **Member functions**: All but simplest implemented outside class definition
- **Documentation**: Function prototypes in class must have comments
- **Data members**: ALL must be private
- **Design principles**:
  - Functions that should be member functions are implemented as member functions
  - Data members should describe attributes of the class
  - Avoid convenience member variables that don't describe the class (e.g., loop variables)
  - Avoid storing calculable values as attributes
  - Avoid duplicated or redundant data attributes

