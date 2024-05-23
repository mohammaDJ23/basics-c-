#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <random>

template<class OutputIt, class Size, class Generator>
constexpr // since C++20
OutputIt generate_n(OutputIt first, Size count, Generator g)
{
    for (Size i = 0; i < count; ++i, ++first)
        *first = g();
 
    return first;
}
 
int main()
{
    std::mt19937 rng; // default constructed, seeded with fixed seed
    std::generate_n(std::ostream_iterator<std::mt19937::result_type>(std::cout, " "), 5, std::ref(rng));
    std::cout << '\n';
}