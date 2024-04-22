#include <algorithm>
#include <array>
#include <iostream>

template<class InputIt, class T>
constexpr InputIt find(InputIt first, InputIt last, const T& value)
{
    for (; first != last; ++first)
        if (*first == value)
            return first;
 
    return last;
}
 
int main()
{
    const auto v = {1, 2, 3, 4};
 
    for (const int n : {3, 5})
        (std::find(v.begin(), v.end(), n) == std::end(v))
            ? std::cout << "v does not contain " << n << '\n'
            : std::cout << "v contains " << n << '\n';
}