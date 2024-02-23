# UnixStyleTextTools

UnixStyleTextTools is a collection of C++ programs inspired by classic Unix command-line tools, designed for text processing tasks such as counting words, displaying file contents, sorting text, and more. This suite of tools is perfect for those looking to perform quick, command-line based text manipulations.

## Getting Started

To use these tools, you'll first need to compile them. Ensure you have a C++ compiler (such as g++) installed on your system.

## Compilation Instructions

Navigate to the UnixStyleTextTools directory and run the following commands to compile each tool:

```bash
g++ avg_name_number_calculator.cpp -o avg_name_number_calculator
g++ cat.cpp -o cat
g++ count.cpp -o count
g++ duplicate_line_counter.cpp -o duplicate_line_counter
g++ fold.cpp -o fold
g++ head.cpp -o head
g++ sort.cpp -o sort
g++ wc.cpp -o wc
```

## Tools Overview

- **avg_name_number_calculator**: Calculates and displays the average length of names and the average number from a list.
  - Usage: `./avg_name_number_calculator input_data_avg_name_num.txt`
- **cat**: Mimics the Unix `cat` command to display file contents.
  - Usage: `./cat [file_name]`
- **duplicate_line_counter**: Counts and displays the number of consecutive duplicate lines.
  - Usage: `./duplicate_line_counter duplicate_line.txt`
- **alphanumeric_filter.cpp**: Processes text from files or standard input, converting non-alphanumeric characters to new lines (`\n`). This tool is particularly useful for text parsing or analysis tasks where alphanumeric content is of interest.
  - Usage: `./alphanumeric_filter [file_name]` for files, or simply `./alphanumeric_filter` for standard input.
- **head**: Displays the first N lines of a file.
  - Usage: `./head -n [number] [file_name]`
- **sort**: Sorts lines of text in files or from standard input.
  - Usage: `./sort -n -r [file_name]`
- **wc**: Counts lines, words, and characters in a file.
  - Usage: `./wc [file_name]`

Each tool is designed for simplicity and ease of use, following the Unix philosophy of doing one thing and doing it well.

## Example Files

- **duplicate_line.txt**: Use with `duplicate_line_counter` to test duplicate line counting functionality.
- **input_data_avg_name_num.txt**: Designed for use with `avg_name_number_calculator` to demonstrate averaging capabilities.

## Contributing

Contributions, bug reports, and improvements are welcome. Feel free to fork this repository and submit your pull requests.


Enjoy using UnixStyleTextTools for your text processing needs!

