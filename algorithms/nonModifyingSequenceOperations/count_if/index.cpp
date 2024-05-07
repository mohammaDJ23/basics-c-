#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>

template<class InputIt, class UnaryPred>
typename std::iterator_traits<InputIt>::difference_type count_if(InputIt first, InputIt last, UnaryPred p)
{
    typename std::iterator_traits<InputIt>::difference_type ret = 0;
    for (; first != last; ++first)
        if (p(*first))
            ++ret;
    return ret;
}
 
int main()
{
    constexpr std::array v{1, 2, 3, 4, 4, 3, 7, 8, 9, 10};
    std::cout << "v: ";
    std::copy(v.cbegin(), v.cend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
 
    // Use a lambda expression to count elements divisible by 4.
    int count_div4 = std::count_if(v.begin(), v.end(), [](int i) { return i % 4 == 0; });
    std::cout << "numbers divisible by four: " << count_div4 << '\n';
 
    // A simplified version of `distance` with O(N) complexity:
    auto distance = [](auto first, auto last)
    {
        return std::count_if(first, last, [](auto) { return true; });
    };
    static_assert(distance(v.begin(), v.end()) == 10);

    return 0;
}