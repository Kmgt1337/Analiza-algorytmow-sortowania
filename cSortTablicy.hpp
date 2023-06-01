#ifndef CSORTTABLICY_HPP
#define CSORTTABLICY_HPP

#include <vector>
#include "Utility.hpp"

class cSortTablicy
{
public:
    enum class ELEMENTS_TYPE
    {
        RANDOM,
        SORTED,
        REVERSE_SORTED,
        ALMOST_SORTED
    };

    void set_bounds(long long lower, long long upper)
    {
        _lower_bound = lower;
        _upper_bound = upper;
    }

    void read_vec_size()
    {
        _n = f_read_number(0);
    }

    std::vector<int> generate_vec(ELEMENTS_TYPE type);

private:
    std::vector<int> generate_random_vec();
    std::vector<int> generate_reverse_sorted_vec();
    std::vector<int> generate_sorted_vec();
    std::vector<int> generate_partially_sorted_vec(float sorted_percent);
    int _n;

    long long _lower_bound;
    long long _upper_bound;
};

#endif
