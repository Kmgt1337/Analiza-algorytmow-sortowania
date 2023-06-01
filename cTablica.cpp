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

void cTablica::heap_sort(std::vector<int>& vec, int n)
{
    for (int i=n/2-1; i>=0; i--)
    {
        heapify(vec, n, i);
    }

    for (int i=n-1; i>0; i--)
    {
        _swap_count++;
        swap(vec[0], vec[i]);
        heapify(vec, i, 0);
    }
}

void cTablica::heapify(std::vector<int>& vec, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    _comp_count++;
    if (l < n && vec[l] > vec[largest]) largest = l;
    _comp_count++;
    if (r < n && vec[r] > vec[largest]) largest = r;
    _comp_count++;
    if (largest != i)
    {
        _swap_count++;
        swap(vec[i], vec[largest]);
        heapify(vec, n, largest);
    }
}

void cTablica::bubble_sort(std::vector<int>& vec)
{
    bool swapped;
    for (int i = 0; i < vec.size() - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < vec.size() - i - 1; j++)
        {
            _comp_count++;
            if (vec[j] > vec[j+1])
            {
                _swap_count++;
                swap(vec[j], vec[j+1]);
                swapped = true;
            }
        }
        _comp_count++;
        if(!swapped) break;
    }
}
