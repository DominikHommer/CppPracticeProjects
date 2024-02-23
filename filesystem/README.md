# Filesystem Utilities

This repository contains a collection of C++ programs that mimic some of the functionalities of common Unix system utilities, focusing on file and directory management using the `std::filesystem` library introduced in C++17. These utilities are designed to demonstrate how to perform operations in C++ that you would typically do with Unix commands like `ls`, `find`, and `grep`, for educational purposes.

## Utilities Overview

Each program is designed to provide a specific functionality related to filesystem operations:

#### `ls.cpp` - Directory and File Lister

Mimics the basic functionality of the Unix `ls` command, listing files and directories within a specified path. It can optionally show the sizes of files and directories in a human-readable format, similar to `ls -lh`.

#### `find.cpp` - Recursive File Finder

Inspired by the Unix `find` command, this program recursively lists all files within a given directory path. It demonstrates how to traverse directories deeply in C++, showcasing functionality similar to running `find <path>`.

#### `match.cpp` - Pattern Search in Files

Resembles the functionality of using Unix `grep` in combination with `find` to search for files containing a specified regular expression pattern. This utility searches through all files in a given directory (and subdirectories) for a regex pattern, emulating `grep -r '<pattern>' <path>`.

## Getting Started

### Requirements

- C++17 compliant compiler

### Compilation

Each program can be compiled using `g++` with support for C++17. Here are the commands for compiling each utility:

For `ls.cpp`:

```bash
g++ -std=c++17 ls.cpp -o ls
```

For `find.cpp`:

```bash
g++ -std=c++17 find.cpp -o find
```

For `match.cpp`:

```bash
g++ -std=c++17 match.cpp -o match
```

### Usage

Each utility can be run from the command line with its respective arguments. For specific usage instructions, refer to the comments within each source file or execute the program without any arguments to see usage information.

## Contributing

Contributions to improve or extend the utilities are welcome! Feel free to fork this repository, make your changes, and submit a pull request.

