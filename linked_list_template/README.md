# Linked List Template in C++

This repository contains a simple implementation of a linked list template in C++. It demonstrates how to define and implement a template class in C++ for creating and managing a singly linked list. The project is structured into a header file, a template implementation file, and a main driver program.

## Project Structure

- `linked_list_template.h`: Header file containing the template class declaration for the linked list.
- `linked_list_template.tpp`: Implementation file for the template class. This includes the definitions of the member functions declared in the header file.
- `main.cpp`: Main driver program that demonstrates the usage of the `list` template class with different operations.
- `Makefile`: A simple Makefile to compile the project using g++ and generate an executable.

## Features

The `list` template class supports the following operations:

- Default construction, copy construction, move construction.
- Copy assignment and move assignment.
- Appending elements to the end of the list.
- Adding another list to the end of the current list.
- Accessing elements by index.
- Getting the size of the list.
- Printing the list elements to the standard output.

## Compilation and Running

Ensure you have a C++ compiler that supports C++17 (or later) installed. This project was tested with the GNU compiler.

To compile the project, simply run:

```bash
make
```

This will generate an executable named `linked_list`. You can run this executable to see the `list` class in action:

```bash
./linked_list
```

To clean up the compiled files, you can use:

```bash
make clean
```

## Usage Example

The `main.cpp` file demonstrates how to use the `list` class with `int` type, including operations like appending elements, accessing elements by index, and utilizing the copy/move constructors and assignment operators. It also shows how to add one list to another and print the contents of a list.

## Contributing

Feel free to fork this repository and submit pull requests to contribute to this project. Whether it's adding new features, fixing bugs, or improving documentation, all contributions are welcome!


