#ifndef LINE_COUNTER_H
#define LINE_COUNTER_H

#include <string>
#include <vector>

size_t count_lines_in_file(const std::string &filename);
size_t count_lines_in_directory(const std::string &directory_path);

#endif