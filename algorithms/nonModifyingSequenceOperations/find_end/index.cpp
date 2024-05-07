#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>

template<class ForwardIt1, class ForwardIt2>
constexpr //< since C++20
ForwardIt1 find_end(ForwardIt1 first, ForwardIt1 last, ForwardIt2 s_first, ForwardIt2 s_last)
{
    if (s_first == s_last)
        return last;
 
    ForwardIt1 result = last;
    while (true)
    {
        ForwardIt1 new_result = std::search(first, last, s_first, s_last);
        if (new_result == last)
            break;
        else
        {
            result = new_result;
            first = result;
            ++first;
        }
    }
    return result;
}

template<class ForwardIt1, class ForwardIt2, class BinaryPred>
constexpr //< since C++20
ForwardIt1 find_end(ForwardIt1 first, ForwardIt1 last, ForwardIt2 s_first, ForwardIt2 s_last, BinaryPred p)
{
    if (s_first == s_last)
        return last;
 
    ForwardIt1 result = last;
    while (true)
    {
        ForwardIt1 new_result = std::search(first, last, s_first, s_last, p);
        if (new_result == last)
            break;
        else
        {
            result = new_result;
            first = result;
            ++first;
        }
    }
    return result;
}
 
auto print_result = [](auto result, const auto& v)
{
    result == v.end()
        ? std::cout << "Sequence not found\n"
        : std::cout << "Last occurrence is at: " << std::distance(v.begin(), result) << '\n';
};
 
int main()
{
    const auto v = {2, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4};
 
    for (auto const& x : {std::array{1, 2, 3}, {4, 5, 6}})
    {
        auto iter = find_end(v.begin(), v.end(), x.begin(), x.end()); // overload (1)
        print_result(iter, v);
    }
 
    for (auto const& x : {std::array{-1, -2, -3}, {-4, -5, -6}})
    {
        auto iter = find_end(v.begin(), v.end(), x.begin(), x.end(), 
            [](int x, int y) { return std::abs(x) == std::abs(y); }); // overload (3)
        print_result(iter, v);
    }

    return 0;
}