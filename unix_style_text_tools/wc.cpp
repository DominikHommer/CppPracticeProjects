#include <iostream>
#include <fstream>
#include <sstream>

// This program extends the functionality of the Unix 'wc' command, allowing users to count lines or characters in a file or standard input.
// It supports '-l' for line counting and '-c' for character counting, providing flexibility in what to count.

int main(int argc, char** argv){
    std::string l = "-l";
    std::string c = "-c";
    if(argc == 1){
        // Counts lines and characters from standard input if no file is specified.
        std::string line;
        std::stringstream ss;
        int line_counter = 0;
        int char_counter = 0;
        while(std::getline(std::cin, line)){
            ss << line;
            line_counter++;
            char_counter += line.length();
        }
        std::cout << "Lines: " << line_counter << " Characters: " << char_counter << std::endl;
    } else if (argc >= 2){
        // Parses command-line arguments to count lines or characters based on specified flags.
        if(argv[1] == l){
            for (int i = 2; i < argc; i++){
                std::ifstream file(argv[i]);
                std::string line;
                int line_counter = 0;
                while(std::getline(file, line)){
                    line_counter++;
                }
                std::cout << "Lines: " << line_counter << " in " << argv[i] << std::endl;
            }
        } else if(argv[1] == c){
            for (int i = 2; i < argc; i++){
                std::ifstream file(argv[i]);
                std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
                std::cout << "Characters: " << content.length() << " in " << argv[i] << std::endl;
            }
        } else {
            // Default case to count both lines and characters for each specified file.
            for(int i = 1; i < argc; i++){
                std::ifstream file(argv[i]);
                std::string line;
                int line_counter = 0, char_counter = 0;
                while(std::getline(file, line)){
                    line_counter++;
                    char_counter += line.length();
                }
                std::cout << "Lines: " << line_counter << " Characters: " << char_counter << " in " << argv[i] << std::endl;
            }
        }
    }
}

