#include <iostream>
#include <regex>
#include <filesystem>
#include <fstream>
#include <string>

namespace fs = std::filesystem;

void find_pattern_in_path(fs::path p, std::regex pattern) {
    for (const auto &entry : fs::recursive_directory_iterator(p)) {
        if (fs::exists(entry) && !fs::is_directory(entry)) {
            std::ifstream file(entry.path());
            if (!file.is_open()) {
                std::cerr << "Could not open file: " << entry.path().filename().string() << std::endl;
                continue;
            }
            std::string line;
            while (std::getline(file, line)) {
                try {
                    if (std::regex_search(line, pattern)) {
                        std::cout << "Match found in: " << entry.path().string() << std::endl;
                        break; // Found a match, no need to check this file further
                    }
                } catch (const std::regex_error& e) {
                    std::cerr << "Regex error: " << e.what() << std::endl;
                    return; // Return from the function if regex error occurs
                }
            }
        }
    }
}

int main(int argc, char** argv) {
    if (argc < 3) {
        std::cerr << "Usage: ./match <path/to/search> '<regex>'\n";
        return -1;
    }
    fs::path p = argv[1];
    if (!fs::exists(p) || !fs::is_directory(p)) {
        std::cerr << "Provided path is not a valid directory.\n";
        return -1;
    }
    try {
        std::regex pattern(argv[2]);
        std::cout << "Searching in: " << p << " for regex pattern: " << argv[2] << std::endl;
        find_pattern_in_path(p, pattern);
        std::cout << "Search completed." << std::endl;
    } catch (const std::regex_error& e) {
        std::cerr << "Regex error: " << e.what() << "\nPlease provide a valid regex pattern.\n";
    }
}


