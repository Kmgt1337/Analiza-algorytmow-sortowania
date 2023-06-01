#include "cTablica.hpp"
#include "Utility.hpp"
#include "cSortTablicy.hpp"

int main()
{
    int lower, upper;
    std::cout << "Podaj od jakiej liczby losujemy: ";
    std::cin >> lower;
    std::cout << "Podaj do jakiej liczby losujemy: ";
    std::cin >> upper;

    cSortTablicy sort;
    sort.set_bounds(lower, upper);
    sort.read_vec_size();
    auto vec = sort.generate_vec(cSortTablicy::ELEMENTS_TYPE::RANDOM);
    //for(int i=0; i<vec.size(); i++) std::cout<<vec[i]<<" ";

    cTablica cc;
    cTimer timer;
    std::pair<int, int> count;

    //===========================================
    auto vec1 = vec;
    cc.reset_counters();
    timer.start();
    cc.quick_sort_lomuto(vec1, 0, vec1.size() - 1);
    timer.stop();

    count = cc.num_of_comp_and_swap();

    std::cout << "\nQuick sort lomuto:\n";
    std::cout << "czas (us) = " << timer.time_in_microseconds();
    std::cout << "\nliczba porownan = " << count.first << ", liczba przestawien = " << count.second << "\n";
    //===========================================

    //===========================================
    auto vec2 = vec;
    cc.reset_counters();
    timer.start();
    cc.quick_sort_hoare(vec2, 0, vec2.size() - 1);
    timer.stop();

    count = cc.num_of_comp_and_swap();
    std::cout << "\n\nQuick sort horae:\n";
    std::cout << "czas (us) = " << timer.time_in_microseconds();
    std::cout << "\nliczba porownan = " << count.first << ", liczba przestawien = " << count.second << "\n";
    //===========================================
    auto vec3 = vec;
    cc.reset_counters();
    timer.start();
    cc.heap_sort(vec3, vec3.size());
    timer.stop();

    count = cc.num_of_comp_and_swap();
    std::cout << "\n\nHeapsort :\n";
    std::cout << "czas (us) = " << timer.time_in_microseconds();
    std::cout << "\nliczba porownan = " << count.first << ", liczba przestawien = " << count.second << "\n";
    //===========================================
    auto vec4 = vec;
    cc.reset_counters();
    timer.start();
    cc.bubble_sort(vec4);
    timer.stop();

    count = cc.num_of_comp_and_swap();
    std::cout << "\n\nBubble sort :\n";
    std::cout << "czas (us) = " << timer.time_in_microseconds();
    std::cout << "\nliczba porownan = " << count.first << ", liczba przestawien = " << count.second << "\n";
    return 0;
}
