#include <algorithm>
#include <array>
#include <complex>
#include <functional>
#include <iostream>

template<class ForwardIt, class T = typename std::iterator_traits<ForwardIt>::value_type>
void replace(ForwardIt first, ForwardIt last, const T& old_value, const T& new_value)
{
    for (; first != last; ++first)
        if (*first == old_value)
            *first = new_value;
}
 
void println(const auto& seq)
{
    for (const auto& e : seq)
        std::cout << e << ' ';
    std::cout << '\n';
}
 
int main()
{
    std::array<int, 10> s{5, 7, 4, 2, 8, 6, 1, 9, 0, 3};

    // Replace all occurrences of 8 with 88.
    std::replace(s.begin(), s.end(), 8, 88);
    println(s);
 
    std::array<std::complex<double>, 2> nums{{{1, 3}, {1, 3}}};
    #ifdef __cpp_lib_algorithm_default_value_type
        std::replace(nums.begin(), nums.end(), {1, 3}, {4, 2});
    #else
        std::replace(nums.begin(), nums.end(), std::complex<double>{1, 3},  std::complex<double>{4, 2});
    #endif
    println(nums);
}