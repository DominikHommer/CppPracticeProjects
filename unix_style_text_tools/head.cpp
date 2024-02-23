#include <iostream>
#include <fstream>
#include <sstream>

// This program mimics the Unix 'head' command functionality, allowing users to print the first N lines from a file or standard input.
// It supports an optional '-n' flag to specify the number of lines to be printed, defaulting to 10 if not specified.

void standard_input(int lines_number = 10){
    // Captures lines from standard input and prints the first N lines.
    std::stringstream ss;
    std::string line;
    while(std::getline(std::cin, line)){
        ss << line << "\n";
    }
    std::string output;
    int head_counter = 0;
    while (std::getline(ss, output) && head_counter < lines_number){
        head_counter++;
        std::cout << output << std::endl;
    }
}

void file_output(int index, int argc, char** argv, int lines_number = 10){
    // Prints the first N lines from each file specified in command-line arguments.
    for(int i = index; i < argc; i++){
        std::fstream file(argv[i]);
        std::string output;
        int head_counter = 0;
        while (std::getline(file, output) && head_counter < lines_number){
            head_counter++;
            std::cout << output << std::endl;
        }
    }
}

int main(int argc, char** argv){
    // Parses command-line arguments to set flags and determine the number of lines to print.
    std::string n = "-n";
    bool number_flag = false;
    int lines_number = 0;
    for(int i = 0; i < argc; i++){
        if(argv[i] == n){
            number_flag = true;
            lines_number = atoi(argv[i+1]);
            break;
        }
    }
    
    if(!number_flag){
        if(argc == 1){
            standard_input();
        } else {
            file_output(1, argc, argv);
        }
    } else {
        if(argc == 3){
            standard_input(lines_number);
        } else {
            file_output(3, argc, argv, lines_number);
        }
    }
}

