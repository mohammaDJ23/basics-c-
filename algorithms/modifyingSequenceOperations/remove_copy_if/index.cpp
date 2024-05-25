#include <algorithm>
#include <complex>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
 
template<class InputIt, class OutputIt, class UnaryPred>
constexpr OutputIt remove_copy_if(InputIt first, InputIt last, OutputIt d_first, UnaryPred p)
{
    for (; first != last; ++first)
        if (!p(*first))
            *d_first++ = *first;
            
    return d_first;
}
 
int main()
{
    // Erase the hash characters '#' on the fly.
    std::string str = "#Return #Value #Optimization";
    std::cout << "before: " << std::quoted(str) << '\n';
 
    std::cout << "after:  \"";
    std::remove_copy(str.begin(), str.end(), std::ostream_iterator<char>(std::cout), '#');
    std::cout << "\"\n";
 
    // Erase {1, 3} value on the fly.
    std::vector<std::complex<double>> nums{{2, 2}, {1, 3}, {4, 8}, {1, 3}};
    std::remove_copy(nums.begin(), nums.end(), std::ostream_iterator<std::complex<double>>(std::cout),
    #ifdef __cpp_lib_algorithm_default_value_type
        {1, 3}); // T gets deduced
    #else
        std::complex<double>{1, 3});
    #endif
}