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

int gen() 
{ 
    static int i {0}; 
    return ++i; 
} 
 
int main()
{
    std::mt19937 rng; // default constructed, seeded with fixed seed
    std::generate_n(std::ostream_iterator<std::mt19937::result_type>(std::cout, " "), 5, std::ref(rng));
    std::cout << '\n';

    std::vector<int> v1(10); 
    std::generate_n(v1.begin(), v1.size(), gen); 
    for (std::vector<int>::iterator i1 = v1.begin(); i1 != v1.end(); ++i1) { 
        std::cout << *i1 << " "; 
    }
    std::cout << std::endl;
    return 0;
}