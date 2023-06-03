#ifndef FILE_HPP
#define FILE_HPP

#include <vector>
#include "Utility.hpp"

class problem_with_file : std::exception
{
public:
    problem_with_file(std::string msg) : _message(msg)
    {}

    const char* what() const noexcept override
    {
        return _message.c_str();
    }

private:
    std::string _message;
};

void f_save_results_to_file(const char* path, const std::vector<cDataSet>& data, cTimer timer);

#endif