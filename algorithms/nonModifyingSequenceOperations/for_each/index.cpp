/*

    Possible implementation
    See also the implementations in libstdc++, libc++ and MSVC stdlib.

*/

template<class InputIt, class UnaryFunc>
constexpr UnaryFunc for_each(InputIt first, InputIt last, UnaryFunc f)
{
    for (; first != last; ++first)
        f(*first);

    return f; // implicit move since C++11
}

#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v {3, -4, 2, -8, 15, 267};

    auto print = [] (const int &n) { std::cout << n << ' '; };

    std::cout << "before:\t";
    std::for_each(v.cbegin(), v.cend(), print);
    std::cout << '\n';

    // increment elements in-place
    std::for_each(v.begin(), v.end(), [] (int &n) { n++; });

    std::cout << "after:\t";
    std::for_each(v.cbegin(), v.cend(), print);
    std::cout << '\n';

    struct Sum
    {
        void operator()(int n) { sum += n; }
        int sum{0};
    };

    // invoke Sum::operator() for each element
    Sum s = std::for_each(v.cbegin(), v.cend(), Sum());
    std::cout << "sum:\t" << s.sum << '\n';
}
