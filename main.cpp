#include "cTablica.hpp"
#include "Utility.hpp"
#include "cSortTablicy.hpp"
#include "SortAnalysis.hpp"
#include "File.hpp"

int main()
{
    std::string path;
    std::cout << "Podaj sciezke pliku do zapisu wynikow: ";
    std::cin >> path;

    long long lower, upper;
    std::cout << "Podaj od jakiej liczby losujemy: ";
    lower = f_read_number<long long>();
    std::cout << "Podaj do jakiej liczby losujemy: ";
    upper = f_read_number<long long>(lower);

    cSortTablicy sort;
    sort.set_bounds(lower, upper);

    std::cout << "Podaj rozmiar tablicy: ";
    sort.read_vec_size();

    cTimer timer;
    int time_option;
    std::cout << "\nPodaj jednostke czasu do mierzenia czasu sortowania (dla rozmiaru tablicy wiekszego od 10000 wybierz co najmniej milisekundy)\n";
    std::cout << "1. mikrosekundy\n";
    std::cout << "2. milisekundy\n";
    std::cout << "3. sekundy\n";
    std::cout << "4. minuty\n";
    std::cout << "Podaj jednostke czasu: ";
    time_option = f_read_number<int>(1, 4);

    switch(time_option)
    {
        case 1:
        {
            timer.set_time_unit(cTimer::TIME::MICROSECONDS);
            break;
        }

        case 2:
        {
            timer.set_time_unit(cTimer::TIME::MILISECONDS);
            break;
        }

        case 3:
        {
            timer.set_time_unit(cTimer::TIME::SECONDS);
            break;
        }

        case 4:
        {
            timer.set_time_unit(cTimer::TIME::MINUTES);
            break;
        }
    }

    int option;
    std::cout << "\nPodaj rodzaj tablicy\n";
    std::cout << "1. losowa\n";
    std::cout << "2. posortowana\n";
    std::cout << "3. odwrotnie posortowana\n";
    std::cout << "4. prawie posortowana (10% elementow na zlej pozycji)\n";
    std::cout << "Podaj opcje: ";
    option = f_read_number<int>(1, 4);

    cTablica c_tab;

    switch(option)
    {
        case 1:
        {
            auto random_vec = sort.generate_vec(cSortTablicy::ELEMENTS_TYPE::RANDOM);
            cDataSet set_bubble = f_make_analysis(random_vec, c_tab, timer, "tablica z losowymi liczbami", SORT_ALG::BUBBLE);
            cDataSet set_quick_lomuto = f_make_analysis(random_vec, c_tab, timer, "tablica z losowymi liczbami", SORT_ALG::QUICK_LOMUTO);
            cDataSet set_quick_hoare = f_make_analysis(random_vec, c_tab, timer, "tablica z losowymi liczbami", SORT_ALG::QUICK_HOARE);
            cDataSet set_heap = f_make_analysis(random_vec, c_tab, timer, "tablica z losowymi liczbami", SORT_ALG::HEAP);

            std::vector<cDataSet> data = {set_bubble, set_quick_lomuto, set_quick_hoare, set_heap};
            f_save_results_to_file(path.c_str(), data, timer);
            
            break;
        }

        case 2:
        {
            auto sorted_vec = sort.generate_vec(cSortTablicy::ELEMENTS_TYPE::SORTED);
            cDataSet set_bubble = f_make_analysis(sorted_vec, c_tab, timer, "tablica posortowana rosnaco", SORT_ALG::BUBBLE);
            cDataSet set_quick_lomuto = f_make_analysis(sorted_vec, c_tab, timer, "tablica posortowana rosnaco", SORT_ALG::QUICK_LOMUTO);
            cDataSet set_quick_hoare = f_make_analysis(sorted_vec, c_tab, timer, "tablica posortowana rosnaco", SORT_ALG::QUICK_HOARE);
            cDataSet set_heap = f_make_analysis(sorted_vec, c_tab, timer, "tablica posortowana rosnaco", SORT_ALG::HEAP);

            std::vector<cDataSet> data = {set_bubble, set_quick_lomuto, set_quick_hoare, set_heap};
            f_save_results_to_file(path.c_str(), data, timer);
            
            break;
        }

        case 3:
        {
            auto reverse_sorted_vec = sort.generate_vec(cSortTablicy::ELEMENTS_TYPE::REVERSE_SORTED);
            cDataSet set_bubble = f_make_analysis(reverse_sorted_vec, c_tab, timer, "tablica posortowana malejaco", SORT_ALG::BUBBLE);
            cDataSet set_quick_lomuto = f_make_analysis(reverse_sorted_vec, c_tab, timer, "tablica posortowana malejaco", SORT_ALG::QUICK_LOMUTO);
            cDataSet set_quick_hoare = f_make_analysis(reverse_sorted_vec, c_tab, timer, "tablica posortowana malejaco", SORT_ALG::QUICK_HOARE);
            cDataSet set_heap = f_make_analysis(reverse_sorted_vec, c_tab, timer, "tablica posortowana malejaco", SORT_ALG::HEAP);

            std::vector<cDataSet> data = {set_bubble, set_quick_lomuto, set_quick_hoare, set_heap};
            f_save_results_to_file(path.c_str(), data, timer);
            
            break;
        }

        case 4:
        {
            auto almost_sorted = sort.generate_vec(cSortTablicy::ELEMENTS_TYPE::ALMOST_SORTED);
            cDataSet set_bubble = f_make_analysis(almost_sorted, c_tab, timer, "10% elementow na zlej pozycji", SORT_ALG::BUBBLE);
            cDataSet set_quick_lomuto = f_make_analysis(almost_sorted, c_tab, timer, "10% elementow na zlej pozycji", SORT_ALG::QUICK_LOMUTO);
            cDataSet set_quick_hoare = f_make_analysis(almost_sorted, c_tab, timer, "10% elementow na zlej pozycji", SORT_ALG::QUICK_HOARE);
            cDataSet set_heap = f_make_analysis(almost_sorted, c_tab, timer, "10% elementow na zlej pozycji", SORT_ALG::HEAP);

            std::vector<cDataSet> data = {set_bubble, set_quick_lomuto, set_quick_hoare, set_heap};
            f_save_results_to_file(path.c_str(), data, timer);
            
            break;
        }
    }
}
