#include <iostream>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

// Function to recursively list all files in a given directory.
void find(const fs::path &p) {
    for (const auto& e : fs::recursive_directory_iterator(p)) {
        std::cout << e.path().string() << std::endl;
    }
}

int main(int argc, char** argv) {
    if (argc == 1) {
        std::cerr << "Error! Usage: find path/to/directory" << std::endl;
        return -1;
    }
    std::vector<fs::path> paths;
    // Collect all provided paths into a vector.
    for (int i = 1; i < argc; i++) {
        paths.emplace_back(argv[i]);
    }
    
    // Execute the find function for each provided path.
    for (const auto &dir : paths) {
        find(dir);
    }
}

