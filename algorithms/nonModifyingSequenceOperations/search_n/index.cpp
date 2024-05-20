#include <algorithm>
#include <cassert>
#include <complex>
#include <iostream>
#include <iterator>
#include <vector>

template<class ForwardIt, class Size, class T = typename std::iterator_traits<ForwardIt>::value_type>
ForwardIt search_n(ForwardIt first, ForwardIt last, Size count, const T& value)
{
    if (count <= 0)
        return first;
 
    for (; first != last; ++first)
    {
        if (!(*first == value))
            continue;
 
        ForwardIt candidate = first;
 
        for (Size cur_count = 1; true; ++cur_count)
        {
            if (cur_count >= count)
                return candidate; // success
 
            ++first;
            if (first == last)
                return last; // exhausted the list
 
            if (!(*first == value))
                break; // too few in a row
        }
    }
    return last;
}

template<class ForwardIt, class Size, class T = typename std::iterator_traits<ForwardIt>::value_type, class BinaryPred>
ForwardIt search_n(ForwardIt first, ForwardIt last, Size count, const T& value, BinaryPred p)
{
    if (count <= 0)
        return first;
 
    for (; first != last; ++first)
    {
        if (!p(*first, value))
            continue;
 
        ForwardIt candidate = first;
 
        for (Size cur_count = 1; true; ++cur_count)
        {
            if (cur_count >= count)
                return candidate; // success
 
            ++first;
            if (first == last)
                return last; // exhausted the list
 
            if (!p(*first, value))
                break; // too few in a row
        }
    }
    return last;
}
 
template<class Container, class Size, class T>
constexpr bool consecutive_values(const Container& c, Size count, const T& v)
{
    return std::search_n(std::begin(c), std::end(c), count, v) != std::end(c);
}
 
int main()
{
    constexpr char sequence[] = ".0_0.000.0_0.";
 
    static_assert(consecutive_values(sequence, 3, '0'));
 
    for (int n : {4, 3, 2})
        std::cout << std::boolalpha
            << "Has " << n << " consecutive zeros: "
            << consecutive_values(sequence, n, '0') << '\n';
 
    std::vector<std::complex<double>> nums{{4, 2}, {4, 2}, {1, 3}};
    #ifdef __cpp_lib_default_template_type_for_algorithm_values
        auto it = std::search_n(nums.cbegin(), nums.cend(), 2, {4, 2});
    #else
        auto it = std::search_n(nums.cbegin(), nums.cend(), 2, std::complex<double>{4, 2});
    #endif
    assert(it == nums.begin());
}