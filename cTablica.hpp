#ifndef CTABLICA_HPP
#define CTABLICA_HPP

#include <vector>
#include <utility>

// Klasa przeprowadzajaca algorytmy sortowania na tablicy
class cTablica
{
public:
    /*
    * Funkcja przeprowadzajaco sortowanie szybkie z podzialem lomuto
    * @param vec tablica do posortowania
    * @param p lewy zakres tablicy (na poczatek ustawiony na 0)
    * @param r prawy zakres tablicy (na poczatek ustawiony na vec.size() - 1)
    */
    void quick_sort_lomuto(std::vector<int>& vec, int p, int r);

    /*
    * Funkcja przeprowadzajaco sortowanie szybkie z podzialem hoare
    * @param vec tablica do posortowania
    * @param p lewy zakres tablicy (na poczatek ustawiony na 0)
    * @param r prawy zakres tablicy (na poczatek ustawiony na vec.size() - 1)
    */
    void quick_sort_hoare(std::vector<int>& vec, int p, int r);

    /*
    * Funkcja przeprowadzajaca sortowanie przez kopcowanie
    * @param vec tablica do posortowania
    * @param n ustawiony na poczatek na vec.size()
    */
    void heap_sort(std::vector<int>& vec, int n);

    /*
    * Funkcja przeprowadzajaca sortowanie babelkowe (wariant wahadlowy (shaker sort))
    * @param vec tablica do posortowania
    */
    void bubble_sort(std::vector<int>& vec);

    /*
    * Funkcja zwracajaca liczbe porownan i przestawien wykonanych podczas danego algorytmu
    * @returns liczba porownan i przestawien
    */
    std::pair<long long, long long> num_of_comp_and_swap()
    {
        return {_comp_count, _swap_count};
    }

    /*
    * Funkcja resetujaca liczbe porownan i przestawien
    */
    void reset_counters()
    {
        _comp_count = 0;
        _swap_count = 0;
    }

private:
    /*
    * Algorytm podzialu lomuto
    * @param vec tablica
    * @param p lewy zakres
    * @param r prawy zakres
    */
    int lomuto_partition(std::vector<int>& vec, int p, int r);

    /*
    * Algorytm podzialu hoare
    * @param vec tablica
    * @param p lewy zakres
    * @param r prawy zakres
    */
    int hoare_partition(std::vector<int>& vec, int p, int r);

    /*
    * Funkcja tworzy kopiec dla danej tablicy
    * @param vec tablica
    * @param n rozmiar kopca
    * @param i indeks do tablicy
    */
    void heapify(std::vector<int>& vec, int n, int i);

    // liczba porownan
    long long _comp_count;

    // liczba przestawien
    long long _swap_count;
};

#endif // CTABLICA_HPP
