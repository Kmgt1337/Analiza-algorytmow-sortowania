#ifndef CSORTTABLICY_HPP
#define CSORTTABLICY_HPP

#include <vector>
#include "Utility.hpp"

// KLasa odpowiedzialna za generowanie tablicy wedlug zadanych wymagan
class cSortTablicy
{
public:
    // Typy tablicy do wygenerowania
    enum class ELEMENTS_TYPE
    {
        // tablica z elementami losowymi
        RANDOM,

        // tablica posortowana rosnaco
        SORTED,

        // tablica posortowana malejaco
        REVERSE_SORTED,

        // tablica prawie posortowana (10% elementow na zlej pozycji)
        ALMOST_SORTED
    };

    /*
    * Funkcja ustawiajaca zakres liczb w tablicy
    * @param lower dolna granica 
    * @param upper gorna granica
    */
    void set_bounds(long long lower, long long upper)
    {
        _lower_bound = lower;
        _upper_bound = upper;
    }

    /*
    * Funkcja wczytujaca rozmiar tablicy
    */
    void read_vec_size()
    {
        _n = f_read_number(0);
    }

    /*
    * Funkcja generujaca tablice zadanego typu
    * @param type typ tablicy
    * @returns tablica
    */
    std::vector<int> generate_vec(ELEMENTS_TYPE type);

private:
    /*
    * Funkcja generujaca tablice z losowymi elementami
    * @returns tablica z losowymi elementami
    */
    std::vector<int> generate_random_vec();

    /*
    * Funkcja generujaca tablice z elementami posortowanymi malejaco
    * @returns tablica z elementami posortowanymi malejaco
    */
    std::vector<int> generate_reverse_sorted_vec();

    /*
    * Funkcja generujaca tablice z elementami posortowanymi rosnaco
    * @returns tablica z elementami posortowanymi rosnaco
    */
    std::vector<int> generate_sorted_vec();

    /*
    * Funkcja generujaca tablice z elementami prawie posortowanymi
    * @returns tablica z elementami prawie posortowanymi
    */
    std::vector<int> generate_partially_sorted_vec(float sorted_percent);

    // rozmiar tablicy
    int _n;

    // dolny zakres liczb w tablicy
    long long _lower_bound;

    // gorny zakres liczb w tablicy
    long long _upper_bound;
};

#endif // CSORTTABLICY_HPP
