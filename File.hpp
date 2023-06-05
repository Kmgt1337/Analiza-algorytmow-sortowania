#ifndef FILE_HPP
#define FILE_HPP

#include <vector>
#include "Utility.hpp"

// Klasa wyjatku zwiazanego z plikiem
class problem_with_file : std::exception
{
public:
    /*
    * Konstruktor
    * @param msg wiadomosc do wyswietlenia
    */
    problem_with_file(std::string msg) : _message(msg)
    {}

    /*
    * Funkcja zwracajaca przechowywana wiadomosc
    * @returns wiadomosc
    */
    const char* what() const noexcept override
    {
        return _message.c_str();
    }

private:
    // wiadomsoc
    std::string _message;
};

/*
* Funkcja zapisujaca do pliku wyniki w formie tabelki
* @param path sciezka do pliku
* @param data dane do zapisania
* @param timer stoper
*/
void f_save_results_to_file(const char* path, const std::vector<cDataSet>& data, cTimer timer);

#endif // FILE_HPP