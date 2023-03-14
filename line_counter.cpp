#include <iostream>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <future>

#include "line_counter.h"

size_t count_lines_in_file (const std::string &filename) {
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Error while opening the file " << filename << std::endl; 
        return 0;
    }

    return std::count(std::istreambuf_iterator<char>(file),
                       std::istreambuf_iterator<char>(), '\n');
}

size_t count_lines_in_directory (const std::string &directory_path) {
    size_t lines = 0;
    std::vector< std::future<size_t> > threads;

    for (const auto &entry : std::filesystem::recursive_directory_iterator(directory_path)) {
        if (entry.is_regular_file()) {
            threads.push_back(std::async(std::launch::async, count_lines_in_file, entry.path()));
        }
    }

    for (auto &future : threads) {
        lines += future.get();
        lines += 1; // last line in the file does not have \n symbol
    }

    return lines;
}