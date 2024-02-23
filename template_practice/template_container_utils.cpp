#include <iostream>
#include <vector>
#include <functional>
#include <string>

// Reverse the elements of a vector in-place.
template<typename T>
void reverse(std::vector<T> &t) {
    for(int i = 0; i < (t.size() / 2); i++) {
        T temp = t[t.size() - 1 - i];
        t[t.size() - 1 - i] = t[i];
        t[i] = temp;
    }
}

// Find and return the maximum element in a vector.
template<typename T>
T max_element(const std::vector<T> &t) {
    T maxElem = t[0];
    for(int i = 1; i < t.size(); i++) {
        if(t[i] > maxElem) {
            maxElem = t[i];
        }
    }
    return maxElem;
}

// Returns the length of a string. This function is used as an example of a custom operation.
int string_length(const std::string &s) {
    return s.length();
}

// Find the index of the element with the maximum result from a given operation.
// The operation is a function that takes a single element of type T and returns an int.
template<typename T, typename Func>
int index_from_max_element(const std::vector<T> &t, Func operation) {
    int maxElem = operation(t[0]);
    int maxIndex = 0;
    for(int i = 1; i < t.size(); i++) {
        int current = operation(t[i]);
        if(current > maxElem) {
            maxElem = current;
            maxIndex = i;
        }
    }
    return maxIndex;
}


int main(int argc, char** argv) {
    if(argc <= 1) {
        std::cerr << "No args given, please provide args like " << argv[0] << " <arg1> <arg2> ..." << std::endl;
        return 0;
    }

    // Example usage with std::string
    std::vector<std::string> strings;
    for(int i = 1; i < argc; i++) {
        strings.push_back(argv[i]);
    }

    std::cout << "Index of longest Word: " << index_from_max_element(strings, string_length) << std::endl;

    reverse(strings);
    
    for(const auto& str : strings) {
        std::cout << str << " ";
    }
    std::cout << std::endl;
    
    // Example usage with int (commented out)
    // std::vector<int> ints = {1, 2, 3, 4, 5};
    // reverse(ints);
    // std::cout << "Reversed ints: ";
    // for(const auto& i : ints) {
    //     std::cout << i << " ";
    // }
    // std::cout << "\nMax element in ints: " << max_element(ints) << std::endl;

    return 0;
}
