#ifndef FILE_HPP
#define FILE_HPP

#include <vector>
#include "Utility.hpp"

void f_save_results_to_file(const char* path, const std::vector<cDataSet>& data, cTimer timer);

#endif