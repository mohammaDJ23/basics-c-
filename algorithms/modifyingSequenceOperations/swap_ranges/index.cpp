#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

template<class ForwardIt1, class ForwardIt2>
constexpr //< since C++20
ForwardIt2 swap_ranges(ForwardIt1 first1, ForwardIt1 last1, ForwardIt2 first2)
{
    for (; first1 != last1; ++first1, ++first2)
        std::iter_swap(first1, first2);
 
    return first2;
}
 
auto print = [](auto comment, auto const& seq)
{
    std::cout << comment;
    for (const auto& e : seq)
        std::cout << e << ' ';
    std::cout << '\n';
};
 
int main()
{
    std::vector<char> v{'a', 'b', 'c', 'd', 'e'};
    std::list<char> l{'1', '2', '3', '4', '5'};
 
    print("Before swap_ranges:\n" "v: ", v);
    print("l: ", l);
 
    std::swap_ranges(v.begin(), v.begin() + 3, l.begin());
 
    print("After swap_ranges:\n" "v: ", v);
    print("l: ", l);
}