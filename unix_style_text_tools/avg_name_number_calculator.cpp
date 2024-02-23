#include <iostream>
#include <fstream>
#include <string>

// This program calculates the average length of names (first and last combined) and the average of numerical values from a file.
// Each line in the file should contain a first name, last name, and a number, separated by spaces.

int main(int argc, char** argv){
    if(argc != 2){
        std::cerr << "Usage: ./avg_name_number_calculator <file_path>" << std::endl;
        return 1;
    }

    std::fstream file(argv[1]);
    if(!file.is_open()){
        std::cerr << "Error opening file: " << argv[1] << std::endl;
        return 1;
    }
    
    double str_len = 0.0, number_value = 0.0;
    int counter = 0;
    std::string vorname, nachname;
    double num;
    
    while(file >> vorname >> nachname >> num){
        str_len += (vorname.length() + nachname.length());
        number_value += num;
        counter++;
    }
    
    if (counter > 0) {
        std::cout << "AVG_NAME_LEN: " << (str_len / counter) << std::endl;
        std::cout << "AVG_NUMBER: " << (number_value / counter) << std::endl;
    } else {
        std::cerr << "No data processed. Ensure the file format is <FirstName> <LastName> <Number>." << std::endl;
    }
    
    return 0;
}

