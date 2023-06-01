#ifndef CTABLICA_HPP
#define CTABLICA_HPP

#include <vector>
#include <utility>

class cTablica
{
public:
    void quick_sort_lomuto(std::vector<int>& vec, int p, int r);
    void quick_sort_hoare(std::vector<int>& vec, int p, int r);
    void heap_sort(std::vector<int>& vec, int n);
    void bubble_sort(std::vector<int>& vec);

    std::pair<int, int> num_of_comp_and_swap()
    {
        return {_comp_count, _swap_count};
    }

    void reset_counters()
    {
        _comp_count = 0;
        _swap_count = 0;
    }

private:
    int lomuto_partition(std::vector<int>& vec, int p, int r);
    int hoare_partition(std::vector<int>& vec, int p, int r);
    void heapify(std::vector<int>& vec, int n, int i);

    int _comp_count;
    int _swap_count;
};

#endif
