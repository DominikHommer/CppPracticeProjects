# Dynamic Array Template in C++

This repository contains a simple implementation of a dynamic array template in C++. It demonstrates how to define and implement a template class in C++ and how to use it with different data types. The project is structured into a header file, a template implementation file, and a main driver program.

## Project Structure

- `dynamic_array_template.h`: Header file containing the template class declaration for the dynamic array.
- `dynamic_array_template.tpp`: Implementation file for the template class. This includes the definitions of the member functions declared in the header file.
- `main.cpp`: Main driver program that demonstrates the usage of the `dynamic_array` template class with different operations.
- `Makefile`: A simple Makefile to compile the project using g++ and generate an executable.

## Features

The `dynamic_array` template class supports the following operations:

- Default construction, copy construction, move construction.
- Copy assignment and move assignment.
- Appending elements to the end of the array.
- Accessing elements by index.
- Getting the size of the array.
- Printing the array elements to the standard output.

## Compilation and Running

Ensure you have a C++ compiler that supports C++17 (or later) installed. This project was tested with the GNU compiler.

To compile the project, simply run:

```bash
make
```

This will generate an executable named `dynamic_array`. You can run this executable to see the `dynamic_array` class in action:

```bash
./dynamic_array
```

To clean up the compiled files, you can use:

```bash
make clean
```

## Usage Example

The `main.cpp` file demonstrates how to use the `dynamic_array` class with `int` type, including operations like appending elements, accessing elements, and utilizing the copy/move constructors and assignment operators.

## Contributing

Feel free to fork this repository and submit pull requests to contribute to this project. Whether it's adding new features, fixing bugs, or improving documentation, all contributions are welcome!



