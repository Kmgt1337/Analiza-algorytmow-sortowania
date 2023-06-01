#include "cSortTablicy.hpp"
#include <random>
using namespace std;

vector<int> cSortTablicy::generate_vec(ELEMENTS_TYPE type)
{
    switch(type)
    {
        case ELEMENTS_TYPE::RANDOM:
        {
            return generate_random_vec();
        }

        case ELEMENTS_TYPE::SORTED:
        {
            return generate_sorted_vec();
        }

        case ELEMENTS_TYPE::REVERSE_SORTED:
        {
            return generate_reverse_sorted_vec();
        }

        case ELEMENTS_TYPE::ALMOST_SORTED:
        {
            return generate_partially_sorted_vec(0.1);
        }
    }
}

vector<int> cSortTablicy::generate_random_vec()
{
    random_device e;
    mt19937 gen(e());
    uniform_int_distribution<int> dist(_lower_bound, _upper_bound);

    vector<int> vec;

    for(int i = 0; i < _n; i++)
    {
        vec.push_back(dist(gen));
    }

    return vec;
}

std::vector<int> cSortTablicy::generate_reverse_sorted_vec()
{
    vector<int> vec;

    for(int i = _n; i > 0; i--)
    {
        vec.push_back(i);
    }

    return vec;
}

std::vector<int> cSortTablicy::generate_sorted_vec()
{
    vector<int> vec;

    for(int i = 0; i < _n; i++)
    {
        vec.push_back(i);
    }

    return vec;
}

std::vector<int> cSortTablicy::generate_partially_sorted_vec(float sorted_percent)
{
    random_device e;
    mt19937 gen(e());
    uniform_int_distribution<int> dist(_lower_bound, _upper_bound);
    vector<int> vec;
    int sorted_part_size=_n*sorted_percent;
    for(int i = 0; i < sorted_part_size; i++)
    {
        vec.push_back(i);
    }
    for(int i=sorted_part_size; i<_n; i++)
    {
        vec.push_back(vec[sorted_part_size-1]+dist(gen));
    }

    return vec;
}
