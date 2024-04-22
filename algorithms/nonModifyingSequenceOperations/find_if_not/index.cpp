#include <algorithm>
#include <array>
#include <iostream>

template<class InputIt, class UnaryPred>
constexpr InputIt find_if_not(InputIt first, InputIt last, UnaryPred q)
{
    for (; first != last; ++first)
        if (!q(*first))
            return first;
 
    return last;
}

int main()
{
    auto is_even = [](int i) { return i % 2 == 0; };
 
    for (auto const& w : {std::array{3, 1, 4}, {1, 3, 5}})
        if (auto it = std::find_if_not(begin(w), end(w), is_even); it != std::end(w))
            std::cout << "w contains an odd number " << *it << '\n';
        else
            std::cout << "w does not contain odd numbers\n";
}