#include <iostream>
#include <fstream>
#include <cctype>
#include <sstream>

// This program processes text from files or standard input, converting non-alphanumeric characters to '\n'.
// It's designed to focus on the alphanumeric content of the text, useful for parsing or text analysis tasks.

void output(const std::string& line){
    // Processes a line of text, converting non-alphanumeric characters to '\n'.
    for(auto c : line){
        if(isalpha(c) || isdigit(c)){
            std::cout << c;
        } else {
            std::cout << "\\n";
        }
    }
    std::cout << std::endl;
}

int main(int argc, char** argv){
    if(argc == 1){
        // Processes standard input if no file is specified.
        std::string input;
        std::stringstream ss;
        while(std::getline(std::cin, input)){
            ss << input << "\n";
        }
        std::string line;
        while (ss >> line) {
            output(line);
        }
    } else if(argc == 2){
        // Processes the specified file.
        std::ifstream file(argv[1]);
        if(file.is_open()){
            std::string line;
            while(std::getline(file, line)){
                output(line);
            }
            file.close();
        }
    } else {
        std::cout << "Too many filenames specified!" << std::endl;
    }
}
