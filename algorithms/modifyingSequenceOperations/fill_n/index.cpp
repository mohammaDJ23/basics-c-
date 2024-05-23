#include <algorithm>
#include <complex>
#include <iostream>
#include <iterator>
#include <vector>

template<class OutputIt, class Size, class T = typename std::iterator_traits<OutputIt>::value_type>
OutputIt fill_n(OutputIt first, Size count, const T& value)
{
    for (Size i = 0; i < count; i++)
        *first++ = value;

    return first;
}
 
int main()
{
    std::vector<int> v1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
 
    // replace values of the first 5 elements with -1
    std::fill_n(v1.begin(), 5, -1);
 
    std::copy_n(v1.cbegin(), v1.size(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
 
    std::vector<std::complex<double>> nums{{1, 3}, {2, 2}, {4, 8}};
    #ifdef __cpp_lib_algorithm_default_value_type
        std::fill_n(nums.begin(), 2, {4, 2});
    #else
        std::fill_n(nums.begin(), 2, std::complex<double>{4, 2});
    #endif
    std::copy_n(nums.cbegin(), nums.size(), std::ostream_iterator<std::complex<double>>(std::cout, " "));
    std::cout << '\n';
}