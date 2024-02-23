#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

// Function to calculate the total size of files in a directory, recursively.
std::uintmax_t directory_size(const fs::path &path) {
    std::uintmax_t size = 0;
    // Iterate through all files in the directory, including subdirectories.
    for (const auto& e : fs::recursive_directory_iterator(path)) {
        if (fs::is_regular_file(e.status())) {
            size += fs::file_size(e.path());
        }
    }
    return size;
}

// Function to list files and directories, showing sizes for directories if flag is set.
void list_files(fs::path p, std::string flag) {
    if (flag.empty()) {
        switch (status(p).type()) {
            case fs::file_type::not_found:
                std::cerr << "File not found: " << p << std::endl;
            case fs::file_type::directory:
                // List all non-hidden files and directories in the given path.
                for (const auto &e : fs::directory_iterator(p)) {
                    if (e.path().filename().string()[0] != '.') {
                        std::cout << e.path().filename().string() << std::endl;
                    }
                }
                break;
            default:
                std::cout << p.string() << std::endl;
        }
    } else {
        // If flag is set, list directories with their sizes in KB, and files with their sizes.
        for (const auto &e: fs::directory_iterator(p)) {
            if (fs::is_directory(e)) {
                fs::path new_path = p / e.path().filename();
                std::uintmax_t size = directory_size(new_path);
                std::cout << "Directory size:\t" << size / 1024 << "\tKB\tDirectory:\t" << e.path().filename().string() << std::endl;
            } else {
                std::cout << "File size:\t" << fs::file_size(e) / 1024 << "\tKB\tFile:\t" << e.path().filename().string() << std::endl;
            }
        }
    }
}

int main(int argc, char** argv) {
    std::string flag;
    if (argc == 1) {
        // List files in the current directory if no arguments are provided.
        fs::path p = ".";
        list_files(p, "");
    } else {
        flag = "-lh";
        if (flag.compare(argv[1]) == 0) {
            // If "-lh" flag is provided, list files with sizes. Check if a path is also provided.
            if (argc == 3) {
                fs::path p = argv[2];
                std::cout << "Listing directory: " << argv[2] << std::endl;
                list_files(p, flag);
            } else {
                // Default to the current directory if no path is provided with the "-lh" flag.
                fs::path p = ".";
                list_files(p, flag);
            }
        } else {
            // List files in the provided directory without size information.
            fs::path p = argv[1];
            list_files(p, "");
        }
    }
    return 0;
}

