#ifndef SORTANALYSIS_HPP
#define SORTANALYSIS_HPp

#include "Utility.hpp"
#include "cTablica.hpp"

enum class SORT_ALG
{
    BUBBLE,
    QUICK_LOMUTO,
    QUICK_HOARE,
    HEAP
};

cDataSet f_make_analysis(std::vector<int> vec, cTablica sort, cTimer timer, std::string arr_type, SORT_ALG alg);

#endif