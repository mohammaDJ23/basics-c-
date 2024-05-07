#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

template<class ForwardIt>
ForwardIt adjacent_find(ForwardIt first, ForwardIt last)
{
    if (first == last)
        return last;
 
    ForwardIt next = first;
    ++next;
 
    for (; next != last; ++next, ++first)
        if (*first == *next)
            return first;
 
    return last;
}

template<class ForwardIt, class BinaryPred>
ForwardIt adjacent_find(ForwardIt first, ForwardIt last, BinaryPred p)
{
    if (first == last)
        return last;
 
    ForwardIt next = first;
    ++next;
 
    for (; next != last; ++next, ++first)
        if (p(*first, *next))
            return first;
 
    return last;
}

int main()
{
    std::vector<int> v1{0, 1, 2, 3, 40, 40, 41, 41, 5};
 
    auto i1 = std::adjacent_find(v1.begin(), v1.end());
    if (i1 == v1.end())
        std::cout << "No matching adjacent elements\n";
    else
        std::cout << "The first adjacent pair of equal elements is at "
            << std::distance(v1.begin(), i1) << ", *i1 = "
            << *i1 << '\n';
 
    auto i2 = std::adjacent_find(v1.begin(), v1.end(), std::greater<int>());
    if (i2 == v1.end())
        std::cout << "The entire vector is sorted in ascending order\n";
    else
        std::cout << "The last element in the non-decreasing subsequence is at "
            << std::distance(v1.begin(), i2) << ", *i2 = " << *i2 << '\n';
}