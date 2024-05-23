#include <algorithm>
#include <complex>
#include <iostream>
#include <vector>

template<class InputIt, class OutputIt, class UnaryPred, class T = typename std::iterator_traits<InputIt>::value_type>
OutputIt replace_copy_if(InputIt first, InputIt last, OutputIt d_first,UnaryPred p, const T& new_value)
{
    for (; first != last; ++first)
        *d_first++ = p(*first) ? new_value : *first;
        
    return d_first;
}
 
void println(const auto& seq)
{
    for (const auto& e : seq)
        std::cout << e << ' ';
    std::cout << '\n';
}
 
int main()
{
    std::vector<short> src{3, 1, 4, 1, 5, 9, 2, 6, 5};
    println(src);
    std::vector<int> dst(src.size());
    std::replace_copy_if(src.cbegin(), src.cend(), dst.begin(), [](short n){ return n > 5; }, 0);
    println(dst);
 
    std::vector<std::complex<double>> src2{{1, 3}, {2, 4}, {3, 5}}, dst2(src2.size());
    println(src2);
    #ifdef __cpp_lib_algorithm_default_value_type
        std::replace_copy_if(src2.cbegin(), src2.cend(), dst2.begin(), 
            [](std::complex<double> z){ return std::abs(z) < 5; },
            {4, 2}); // Possible, since the T is deduced.
    #else
        std::replace_copy_if(src2.cbegin(), src2.cend(), dst2.begin(),
            [](std::complex<double> z){ return std::abs(z) < 5; },
            std::complex<double>{4, 2});
    #endif
    println(dst2);
}