#include "File.hpp"
#include <fstream>
#include <iomanip>

using namespace std;

void f_save_results_to_file(const char* path, const std::vector<cDataSet>& data, cTimer timer)
{
    ofstream file(path, ios::app);
    if(!file.good())
    {
        //throw
    }

    file << setw(20) << "Nazwa metody sortowania\t";
    file << setw(15) << "Dlugosc\t";
    file << setw(data.at(0)._arr_type.size() / 2) << "Rodzaj tablicy\t";
    file << setw(data.at(0)._arr_type.size() - (data.at(0)._arr_type.size() / 6)) << "Porownania\t";
    file << setw(15) << "Przestawienia\t";
    file << setw(10) << "Czas [" + timer.time_unit() << "]\t";
    file << std::endl;

    for(const auto& e : data)
    {
        file << setw(25) << e._method_name << "\t";
        file << setw(8) << e._n << "\t";
        file << setw(data.at(0)._arr_type.size() / 2) << e._arr_type << "\t";
        file << setw(10) << e._comp_count << "\t"; 
        file << setw(10) << e._swap_count << "\t";
        file << setw(10) << e._time_us << std::endl;
    }
    file << std::endl;

    file.close();
}