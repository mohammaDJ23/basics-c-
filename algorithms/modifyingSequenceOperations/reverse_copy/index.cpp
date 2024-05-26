#include <algorithm>
#include <iostream>
#include <vector>

template<class BidirIt, class OutputIt>
constexpr // since C++20
OutputIt reverse_copy(BidirIt first, BidirIt last, OutputIt d_first)
{
    for (; first != last; ++d_first)
        *d_first = *(--last);
        
    return d_first;
}

int main()
{
    auto print = [](const std::vector<int>& v)
    {
        for (const auto& value : v)
            std::cout << value << ' ';
        std::cout << '\n';
    };
 
    std::vector<int> v{1, 2, 3};
    print(v);
 
    std::vector<int> destination(3);
    std::reverse_copy(std::begin(v), std::end(v), std::begin(destination));
    print(destination);
 
    std::reverse_copy(std::rbegin(v), std::rend(v), std::begin(destination));
    print(destination);
}