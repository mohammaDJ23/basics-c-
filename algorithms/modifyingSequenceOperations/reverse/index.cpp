#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

template<class BidirIt>
constexpr // since C++20
void reverse(BidirIt first, BidirIt last)
{
    using iter_cat = typename std::iterator_traits<BidirIt>::iterator_category;
 
    // Tag dispatch, e.g. calling reverse_impl(first, last, iter_cat()),
    // can be used in C++14 and earlier modes.
    if constexpr (std::is_base_of_v<std::random_access_iterator_tag, iter_cat>)
    {
        if (first == last)
            return;
 
        for (--last; first < last; (void)++first, --last)
            std::iter_swap(first, last);
    }
    else
        while (first != last && first != --last)
            std::iter_swap(first++, last);
}
 
void println(auto rem, auto const& v)
{
    for (std::cout << rem; auto e : v)
        std::cout << e << ' ';
    std::cout << '\n';
}
 
int main()
{
    std::vector<int> v {1, 2, 3};
    std::reverse(v.begin(), v.end());
    println("after reverse, v = ", v);
 
    int a[] = {4, 5, 6, 7};
    std::reverse(std::begin(a), std::end(a));
    println("after reverse, a = ", a);
}