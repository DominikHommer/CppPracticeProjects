# Template Practice Programs

This directory contains a collection of C++ programs designed to demonstrate various uses of templates for generic programming. Each program showcases different template techniques, from creating dynamic arrays and utilizing functors to generic swap functions. To maintain simplicity and ensure the examples are easily digestible, components within each program have not been separated into different files.

## Programs Overview

### 1. Generic Swap Functions (`generic_swap_functions.cpp`)

**Purpose**: Demonstrates the use of templates to create generic functions that can swap values of any type, including swapping elements within a vector in pairs.

**How to Use**: Compile and run the program. It will execute predefined swap operations, including swapping two integers, swapping entire vectors, and swapping adjacent pairs within a vector. There are no command-line arguments for this program; it serves as a straightforward demonstration of template functions in action.

### 2. Template Container Utils (`template_container_utils.cpp`)

**Purpose**: Showcases a dynamic array implementation using templates, allowing for a flexible container that can grow as needed. It includes basic functionalities such as appending elements and accessing elements by index.

**How to Use**: This program is more of a library than a standalone executable with user interaction. To see it in action, review the code and consider extending `main` to demonstrate appending and accessing elements in the dynamic array.

### 3. Dynamic Array Functor Analysis (`dynamic_array_functor_analysis.cpp`)

**Purpose**: Explores the use of a functor (a class that overloads the `operator()`) with a dynamic array template class. It specifically demonstrates how to use a functor to perform custom operations on elements of the dynamic array, such as finding the string with the most occurrences of a specified character.

**How to Use**: Compile and run the program with command-line arguments representing strings. The program will append these strings to a dynamic array and use the `maximize_by_letter` functor to identify the string with the most occurrences of the letter 'e'. For example:

```bash
g++ -std=c++17 dynamic_array_functor_analysis.cpp -o dynamic_array_functor_analysis
./dynamic_array_functor_analysis hello world template practice
```

## Compilation

Each program can be compiled with a C++ compiler that supports the C++17 standard or later. For example, to compile `generic_swap_functions.cpp`, you can use the following command:

```bash
g++ -std=c++17 generic_swap_functions.cpp -o generic_swap_functions
```

Replace `generic_swap_functions.cpp` with the filename of the program you wish to compile.

## Note on Structure

For clarity and ease of navigation, the programs within this directory have been structured to reside in single files. This approach has been chosen to simplify the learning process, making it easier for those who are beginning their journey in C++ and template programming to understand and follow along without the distraction of navigating through multiple files for each concept.


## Contributing

Feel free to dive into each program, modify the code, and experiment with the templates. Contributions to extend these programs or add new template-based exercises are welcome.

