#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <chrono>
#include <vector>
#include <iostream>
#include <limits>

class cTimer
{
public:
    enum class TIME
    {
        NANOSECONDS,
        MICROSECONDS,
        MILISECONDS,
        SECONDS,
        MINUTES
    };

    void start()
    {
        _start = std::chrono::steady_clock::now();
    }

    void stop()
    {
        _end = std::chrono::steady_clock::now();
    }

    void set_time_unit(TIME time)
    {
        _time_unit = time;
    }

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
        }
    }

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
        }
    }

    long long time_in_nanoseconds()
    {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(_end - _start).count();
    }

    long long time_in_seconds()
    {
        return std::chrono::duration_cast<std::chrono::seconds>(_end - _start).count();
    }

    long long time_in_microseconds()
    {
        return std::chrono::duration_cast<std::chrono::microseconds>(_end - _start).count();
    }

    long long time_in_miliseconds() 
    {
        return std::chrono::duration_cast<std::chrono::milliseconds>(_end - _start).count();
    }

    long long time_in_minutes()
    {
        return std::chrono::duration_cast<std::chrono::minutes>(_end - _start).count();
    }

private:
    TIME _time_unit;
    std::chrono::steady_clock::time_point _start;
    std::chrono::steady_clock::time_point _end;
};

struct cDataSet
{
    std::string _method_name;
    unsigned int _n;
    std::string _arr_type;
    long long _comp_count;
    long long _swap_count;
    long long _time_us;
};

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

#endif