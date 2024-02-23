#include <iostream>
#include <vector>
#include <stdexcept>

// Template function to swap two values
template<typename X>
void swap(X& a, X& b) {
    X temp = a;
    a = b;
    b = temp;
}

// Template function to swap adjacent pairs in a vector
template <typename T>
void swapPairs(std::vector<T>& v) {
    if (v.size() % 2 != 0) {
        throw std::invalid_argument("Vector must have an even length.");
    }

    for (size_t i = 0; i < v.size(); i += 2) {
        swap(v[i], v[i + 1]);
    }
}

int main() {
    // Demonstrate swapping two integers
    int a = 2, b = 10;
    swap(a, b);
    std::cout << "Swapped a and b: " << a << " " << b << std::endl;

    // Prepare two vectors of integers
    std::vector<int> v1{1, 2, 3, 4, 5, 6};
    std::vector<int> v2{10, 20, 30, 40, 50, 60};

    // Swap entire vectors
    swap(v1, v2);
    std::cout << "Swapped entire vectors v1 and v2:\n";
    for(size_t i = 0; i < v1.size(); i++){
        std::cout << "v1[" << i << "]: " << v1[i] << ", v2[" << i << "]: " << v2[i] << std::endl;
    }

    // Swap pairs within a vector
    try {
        swapPairs(v1);
        std::cout << "Swapped pairs in v1:\n";
        for(const auto& elem : v1){
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

