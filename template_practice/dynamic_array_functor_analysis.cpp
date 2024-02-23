#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>

// Template class for a dynamic array
template<typename T>
class dynamic_array {
    int len = 0;  // Length of the array
    T *data = nullptr;  // Pointer to the array data

public:
    // Constructors
    dynamic_array() = default;
    dynamic_array(int n) : len(n), data(new T[n]) {}

    // Copy constructor
    dynamic_array(const dynamic_array &other) : len(other.len), data(new T[other.len]) {
        for(int i = 0; i < len; i++) {
            data[i] = other.data[i];
        }
    }

    // Copy assignment operator
    dynamic_array& operator=(const dynamic_array &other) {
        if(&other == this) return *this;
        delete [] data;
        len = other.len;
        data = new T[len];
        for(int i = 0; i < len; i++) {
            data[i] = other.data[i];
        }
        return *this;
    }

    // Move constructor
    dynamic_array(dynamic_array &&other) noexcept : len(other.len), data(other.data) {
        other.data = nullptr;
        other.len = 0;
    }

    // Move assignment operator
    dynamic_array& operator=(dynamic_array &&other) noexcept {
        delete [] data;
        len = other.len;
        data = other.data;
        other.data = nullptr;
        other.len = 0;
        return *this;
    }

    // Destructor
    ~dynamic_array() {
        delete [] data;
    }

    // Append an element to the dynamic array
    void append(T value) {
        T *new_data = new T[len + 1];
        for(int i = 0; i < len; i++) {
            new_data[i] = data[i];
        }
        new_data[len] = value;
        len++;
        delete [] data;
        data = new_data;
    }

    // Get the size of the array
    int size() const {
        return len;
    }

    // Index operator to access elements
    T& operator[](int i) {
        assert(i >= 0 && i < len);
        return data[i];
    }

    // Output operator to print the array elements
    friend std::ostream& operator<<(std::ostream &os, const dynamic_array &d) {
        for(int i = 0; i < d.len; i++) {
            os << d.data[i] << ", ";
        }
        return os;
    }
};

// Functor class for maximizing by letter count in a string
class maximize_by_letter {
    char c;

public:
    maximize_by_letter(char c) : c(c) {}
    
    // Functor operator
    int operator()(const std::string &str) const {
        return std::count(str.begin(), str.end(), c);
    }
};

// Function template to find the element with the maximum result from a given functor
template<template <typename> class container, typename T>
auto f(container<T> &data, maximize_by_letter &func) {
    T max_element;
    int max_count = -1;
    
    for(int i = 0; i < data.size(); i++) {
        int count = func(data[i]);
        if(count > max_count) {
            max_count = count;
            max_element = data[i];
        }
    }
    return max_element;
}

// Main function demonstrating the usage of dynamic_array and maximize_by_letter
int main(int argc, char** argv) {
    if(argc <= 1) {
        std::cerr << "No args given, please provide args like " << argv[0] << " <arg1> <arg2> ..." << std::endl;
        return 0;
    }
    dynamic_array<std::string> args;
    for(int i = 1; i < argc; i++) {
        args.append(argv[i]);
    }
    maximize_by_letter count('a');
    std::string most_as = f(args, count);
    std::cout << "Word with most a's: " << most_as << std::endl;
}

