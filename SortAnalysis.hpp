#ifndef SORTANALYSIS_HPP
#define SORTANALYSIS_HPp

#include "Utility.hpp"
#include "cTablica.hpp"

// Rodzaj algorytmu do sortowania
enum class SORT_ALG
{
    // sorotwanie babelkowe (wariant wahadlowy (shaker sort))
    BUBBLE,

    // sorotwanie szybkie z podzialem lomuto
    QUICK_LOMUTO,

    // sortowanie szybkie z podzialem hoare
    QUICK_HOARE,

    // sortowanie przez kopcowanie
    HEAP
};

/*
* Funkcja wykonujaca analize danego algorytmu sortowania (liczba porownan, przestawien, czas wykonania)
* @param vec tablica
* @param sort obiekt klasy cTablica
* @param timer stoper
* @param arr_type rodzaj tablicy
* @param alg rodzaj algorytmu
* @returns dane o przeprowadzonym algorytmie sortowania
*/
cDataSet f_make_analysis(std::vector<int> vec, cTablica sort, cTimer timer, std::string arr_type, SORT_ALG alg);

#endif