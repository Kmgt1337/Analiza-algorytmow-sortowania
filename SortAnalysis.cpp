#include "SortAnalysis.hpp"
using namespace std;

cDataSet f_make_analysis(vector<int> vec, cTablica sort, cTimer timer, std::string arr_type, SORT_ALG alg)
{
    switch(alg)
    {
        case SORT_ALG::BUBBLE:
        {
            sort.reset_counters();
            timer.start();
            sort.bubble_sort(vec);
            timer.stop();
            auto count = sort.num_of_comp_and_swap();

            cDataSet set{"Sortowanie babelkowe", vec.size(), arr_type, count.first, count.second, timer.time()};
            return set;
        }

        case SORT_ALG::QUICK_LOMUTO:
        {
            sort.reset_counters();
            timer.start();
            sort.quick_sort_lomuto(vec, 0, vec.size() - 1);
            timer.stop();
            auto count = sort.num_of_comp_and_swap();

            cDataSet set{"Sortowanie szybkie lomuto", vec.size(), arr_type, count.first, count.second, timer.time()};
            return set;
        }

        case SORT_ALG::QUICK_HOARE:
        {
            sort.reset_counters();
            timer.start();
            sort.quick_sort_hoare(vec, 0, vec.size() - 1);
            timer.stop();
            auto count = sort.num_of_comp_and_swap();

            cDataSet set{"Sortowanie szybkie hoare", vec.size(), arr_type, count.first, count.second, timer.time()};
            return set;
        }

        case SORT_ALG::HEAP:
        {
            sort.reset_counters();
            timer.start();
            sort.heap_sort(vec, vec.size());
            timer.stop();
            auto count = sort.num_of_comp_and_swap();

            cDataSet set{"Sortowanie przez kopcowanie", vec.size(), arr_type, count.first, count.second, timer.time()};
            return set;
        }
    }
}