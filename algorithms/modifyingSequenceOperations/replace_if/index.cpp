#include <algorithm>
#include <array>
#include <complex>
#include <functional>
#include <iostream>

template<class ForwardIt, class UnaryPred, class T = typename std::iterator_traits<ForwardIt>::value_type>
void replace_if(ForwardIt first, ForwardIt last, UnaryPred p, const T& new_value)
{
    for (; first != last; ++first)
        if (p(*first))
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
 
    // Replace all values less than 5 with 55.
    std::replace_if(s.begin(), s.end(), std::bind(std::less<int>(), std::placeholders::_1, 5), 55);
    println(s);
}