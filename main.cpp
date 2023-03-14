#include <iostream>

#include "line_counter.h"

int main (int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: line_counter <directory_path>" << std::endl;
        return 1;
    }

    std::string directory_path = argv[1];
    size_t lines_total = count_lines_in_directory(directory_path);
    std::cout << lines_total << std::endl;

    return 0;
}