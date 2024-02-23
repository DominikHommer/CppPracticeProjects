#include <iostream>
#include <fstream>
#include <string>

// This program counts and prints the number of consecutive duplicate lines in files or standard input.
// For each unique line, it outputs the count followed by the line content.

void process_lines(std::istream& input) {
    std::string curr_line, prev_line;
    int line_detection = 1; // Start counting from 1 for the first occurrence

    while(std::getline(input, curr_line)){
        if(curr_line == prev_line) {
            line_detection++;
        } else {
            if(!prev_line.empty()) { // Avoid printing before any line is read
                std::cout << line_detection << " " << prev_line << std::endl;
            }
            prev_line = curr_line;
            line_detection = 1; // Reset counter for a new line
        }
    }
    // Ensure the last line count and content are printed.
    if(!prev_line.empty()) {
        std::cout << line_detection << " " << prev_line << std::endl;
    }
}

int main(int argc, char** argv){
    if(argc == 1){
        std::cout << "Standard input mode. Please type your input:" << std::endl;
        process_lines(std::cin); // Process lines from standard input
    } else {
        for(int i = 1; i < argc; i++){
            std::ifstream file(argv[i]);
            if(file.is_open()){
                process_lines(file); // Process lines from file
                file.close();
            } else {
                std::cerr << "Could not open file: " << argv[i] << std::endl;
            }
        }
    }
    return 0;
}


