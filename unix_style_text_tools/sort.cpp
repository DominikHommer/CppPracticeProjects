#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

// Reads lines from standard input and returns them as a vector of strings.
std::vector<std::string> read_standard_input() {
    std::vector<std::string> lines;
    std::string line;
    while(std::getline(std::cin, line)) {
        lines.push_back(line);
    }
    return lines;
}

// Reads lines from a file, sorts them according to the specified flags, and returns the sorted lines.
std::vector<std::string> read_file(std::fstream &file, bool number_flag = false, bool reversed_flag = false) {
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    // Close the file after reading.
    file.close();
    
    // Sort the lines based on the flags for numeric values and reverse order.
    std::sort(lines.begin(), lines.end(), [number_flag, reversed_flag](const std::string &a, const std::string &b) {
        if (number_flag) {
            // Attempt numeric sort if the flag is set, with error handling for non-numeric strings.
            try {
                int numA = std::stoi(a);
                int numB = std::stoi(b);
                return reversed_flag ? numB < numA : numA < numB;
            } catch (const std::invalid_argument&) {
                // Fallback to lexicographical sort if conversion fails.
                return reversed_flag ? b < a : a < b;
            }
        } else {
            return reversed_flag ? b < a : a < b;
        }
    });
    
    return lines;
}

// Prints the sorted lines.
void print_sorted_lines(std::vector<std::string> lines){
    for(const auto& line : lines){
        std::cout << line << std::endl;
    }
}

int main(int argc, char** argv){
    bool reversed_flag = false;
    bool number_flag = false;
    int fileStartIndex = 1;

    for(int j = 1; j < argc; j++){
        if(std::string(argv[j]) == "-n"){
            number_flag = true;
            fileStartIndex = std::max(fileStartIndex, j + 1);
        } else if(std::string(argv[j]) == "-r"){
            reversed_flag = true;
            fileStartIndex = std::max(fileStartIndex, j + 1);
        }
    }
    
    if(argc == 1 || (argc == 2 && (number_flag || reversed_flag))) {
        auto lines = read_standard_input();
        print_sorted_lines(lines);
    } else {
        for(int i = fileStartIndex; i < argc; i++){
            std::fstream file(argv[i]);
            if(file.is_open()){
                auto sorted_lines = read_file(file, number_flag, reversed_flag);
                print_sorted_lines(sorted_lines);
            } else {
                std::cerr << "Error opening file: " << argv[i] << std::endl;
            }
        }
    }
    return 0;
}



