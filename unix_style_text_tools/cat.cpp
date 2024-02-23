#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

// Prints the contents of a file with optional line numbering.
void print_file(std::string file_name, bool number_flag) {
    std::ifstream file(file_name);
    std::string line;
    int number = 1;

    while(std::getline(file, line)) {
        if(number_flag) {
            std::cout << number++ << " " << line << std::endl;
        } else {
            std::cout << line << std::endl;
        }
    }
    file.close();
}

// Reads from standard input and prints to standard output, with optional line numbering.
void print_standard_input(bool number_flag) {
    std::string line;
    std::stringstream ss;
    while(std::getline(std::cin, line)) {
        ss << line << "\n";
    }
    std::string output_line;
    int number = 1; 

    while(std::getline(ss, output_line)) {
        if(number_flag) {
            std::cout << number++ << " " << output_line << std::endl;
        } else {
            std::cout << output_line << std::endl;
        }
    }
}

int main(int argc, char** argv) {
    bool number_flag = false; // Flag to determine if line numbers should be printed.

    // Process command-line arguments to configure the behavior of the program.
    if(argc == 2 && strcmp(argv[1], "-n") != 0) {
        print_file(argv[1], number_flag);
    } else if(argc == 3 && strcmp(argv[1], "-n") == 0) {
        number_flag = true;
        print_file(argv[2], number_flag);
    } else if(argc == 1) {
        print_standard_input(number_flag);
    } else if(argc == 2 && strcmp(argv[1], "-n") == 0) {
        number_flag = true;
        print_standard_input(number_flag);
    }

    return 0;
}

