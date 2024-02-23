# Associative Array Template in C++

This repository contains a simple implementation of an associative array template in C++. It demonstrates how to define and implement a template class in C++ for creating and managing an associative array, which is a collection of key-value pairs. This project is structured into a header file, a template implementation file, and a main driver program.

## Project Structure

- `associative_array.h`: Header file containing the template class declaration for the associative array.
- `associative_array.tpp`: Implementation file for the template class. This includes the definitions of the member functions declared in the header file.
- `main.cpp`: Main driver program that demonstrates the usage of the `associative_array` template class with different operations.
- `Makefile`: A simple Makefile to compile the project using g++ and generate an executable.

## Features

The `associative_array` template class supports the following operations:

- Insertion and retrieval of elements based on a key.
- Automatic creation of a new element if the key does not exist when accessed.
- Exception throwing if a non-existent key is accessed in a const context.

## Compilation and Running

Ensure you have a C++ compiler that supports C++17 (or later) installed. This project was tested with the GNU compiler.

To compile the project, simply run:

```bash
make
```

This will generate an executable named `associative_array`. You can run this executable to see the `associative_array` class in action:

```bash
./associative_array
```

To clean up the compiled files, you can use:

```bash
make clean
```

## Usage Example

The `main.cpp` file demonstrates how to use the `associative_array` class with `std::string` as the key type and `int` as the value type. It includes operations like inserting elements and attempting to access elements with both existing and non-existing keys.

## Contributing

Feel free to fork this repository and submit pull requests to contribute to this project. Whether it's adding new features, fixing bugs, or improving documentation, all contributions are welcome!


