#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <chrono>
#include <vector>
#include <iostream>
#include <limits>

class cTimer
{
public:
    void start()
    {
        _start = std::chrono::high_resolution_clock::now();
    }

    void stop()
    {
        _end = std::chrono::high_resolution_clock::now();
    }

    long long time_in_microseconds()
    {
        return std::chrono::duration_cast<std::chrono::microseconds>(_end - _start).count();
    }

    long long time_in_miliseconds() 
    {
        return std::chrono::duration_cast<std::chrono::milliseconds>(_end - _start).count();
    }

private:
    std::chrono::high_resolution_clock::time_point _start;
    std::chrono::high_resolution_clock::time_point _end;
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