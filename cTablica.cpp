#include "cTablica.hpp"
using namespace std;

int cTablica::lomuto_partition(std::vector<int> &vec, int p, int r)
{
    int x = vec[r];
    int i = p - 1;

    for(int j = p; j < r; j++)
    {
        _comp_count++;
        if(vec.at(j) <= x)
        {
            i++;
            _swap_count++;
            swap(vec[i], vec[j]);
        }
    }

    _swap_count++;
    swap(vec[i + 1], vec[r]);

    return ++i;
}

void cTablica::quick_sort_lomuto(std::vector<int>& vec, int p, int r)
{
    if(p < r)
    {
        int q = lomuto_partition(vec, p, r);
        quick_sort_lomuto(vec, p, q - 1);
        quick_sort_lomuto(vec, q + 1, r);
    }
}

int cTablica::hoare_partition(std::vector<int> &vec, int p, int r)
{
    int x = vec[p];
    int i = p - 1;
    int j = r + 1;

    while(true)
    {
        do
        {
            j--;
            _comp_count++;
        } while (vec[j] > x);
        _comp_count++;

        do
        {
            i++;
            _comp_count++;
        } while (vec[i] < x);
        _comp_count++;

        if (i >= j) 
        {
            return j;
        }

        _swap_count++;
        swap(vec[i], vec[j]);
    }
}

void cTablica::quick_sort_hoare(std::vector<int>& vec, int p, int r)
{
    if(p < r)
    {
        int q = hoare_partition(vec, p, r);
        quick_sort_hoare(vec, p, q);
        quick_sort_hoare(vec, q + 1, r);
    }
}

