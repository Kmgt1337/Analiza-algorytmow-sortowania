#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <chrono>
#include <vector>
#include <iostream>
#include <limits>

// Klasa stopera
class cTimer
{
public:
    // Jednostka mierzonego czasu
    enum class TIME
    {
        // nanosekundy (ns)
        NANOSECONDS,

        // mikrosekundy (us)
        MICROSECONDS,

        // milisekundy (ms)
        MILISECONDS,

        // sekundy (s)
        SECONDS,

        // minuty (min)
        MINUTES
    };
    
    /*
    * Funkcja rozpoczynajaca pomiar czasu
    */
    void start()
    {
        _start = std::chrono::steady_clock::now();
    }

    /*
    * Funkcja konczaca pomiar czasu
    */
    void stop()
    {
        _end = std::chrono::steady_clock::now();
    }

    /*
    * Funkcja ustawiajaca jednostke czasu
    * @param time jednostka czasu
    */
    void set_time_unit(TIME time)
    {
        _time_unit = time;
    }

    /*
    * Funkcja zwracajaca jednostke czasu (domyslnie ms)
    * @returns jednostka czasu
    */
    std::string time_unit()
    {
        switch(_time_unit)
        {
            case TIME::NANOSECONDS:
            {
                return "ns";
            }

            case TIME::MICROSECONDS:
            {
                return "us";
            }
            
            case TIME::MILISECONDS:
            {
                return "ms";
            }

            case TIME::SECONDS:
            {
                return "s";
            }

            case TIME::MINUTES:
            {
                return "min";
            }

            default:
            {
                return "ms";
            }
        }
    }

    /*
    * Funkcja zwracajaca czas zmierzony pomiedzy start() i stop() w zadanej jednostce (domyslnie ms)
    */
    long long time()
    {
        switch(_time_unit)
        {
            case TIME::NANOSECONDS:
            {
                return time_in_nanoseconds();
            }

            case TIME::MICROSECONDS:
            {
                return time_in_microseconds();
            }
            
            case TIME::MILISECONDS:
            {
                return time_in_miliseconds();
            }

            case TIME::SECONDS:
            {
                return time_in_seconds();
            }

            case TIME::MINUTES:
            {
                return time_in_minutes();
            }

            default:
            {
                return time_in_miliseconds();
            }
        }
    }

    /*
    * Funkcja zwracajaca czas w nanosekundach
    * @returns czas w nanosekundach
    */
    long long time_in_nanoseconds()
    {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(_end - _start).count();
    }

    /*
    * Funkcja zwracajaca czas w sekundach
    * @returns czas w sekundach
    */
    long long time_in_seconds()
    {
        return std::chrono::duration_cast<std::chrono::seconds>(_end - _start).count();
    }

    /*
    * Funkcja zwracajaca czas w mikrosekundach
    * @returns czas w mikrosekundach
    */
    long long time_in_microseconds()
    {
        return std::chrono::duration_cast<std::chrono::microseconds>(_end - _start).count();
    }

    /*
    * Funkcja zwracajaca czas w milisekundach
    * @returns czas w milisekundach
    */
    long long time_in_miliseconds() 
    {
        return std::chrono::duration_cast<std::chrono::milliseconds>(_end - _start).count();
    }

    /*
    * Funkcja zwracajaca czas w minutach
    * @returns czas w minutach
    */
    long long time_in_minutes()
    {
        return std::chrono::duration_cast<std::chrono::minutes>(_end - _start).count();
    }

private:   
    // jednostka czasu (domyslnie ms)
    TIME _time_unit = TIME::MILISECONDS;

    // zegar - czas poczatku
    std::chrono::steady_clock::time_point _start;

    // zegar - czas zakonczenia
    std::chrono::steady_clock::time_point _end;
};

// Klasa bedaca zestawem danych z analizy algorytmu sortowania
struct cDataSet
{  
    // nazwa algorytmu
    std::string _method_name;

    // rozmiar tablicy
    unsigned int _n;

    // nazwa rodzaju tablicy
    std::string _arr_type;

    // liczba porownan
    long long _comp_count;

    // liczba przestawien
    long long _swap_count;

    // jednostka czasu w mierzeniu czasu wykonania algorytmu
    long long _time_us;
};

/*
* Funkcja wczytujaca liczbe typu T z zadanego przedzialu
* @param min dolna grancia
* @param max gorna granica
* @returns liczba typu T
*/
template <typename T>
T f_read_number(T min = std::numeric_limits<T>::min(), T max = std::numeric_limits<T>::max())
{
	T num;
	std::cin >> num;

	while (num < min || num > max)
	{
		std::cout << "!";
		std::cin >> num;
	}

	return num;
}

#endif // UTILITY_HPP