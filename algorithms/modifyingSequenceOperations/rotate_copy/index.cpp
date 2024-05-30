#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

template<class ForwardIt, class OutputIt>
constexpr // since C++20
OutputIt rotate_copy(ForwardIt first, ForwardIt n_first, ForwardIt last, OutputIt d_first)
{
    d_first = std::copy(n_first, last, d_first);
    return std::copy(first, n_first, d_first);
}
 
int main()
{
    std::vector<int> src{1, 2, 3, 4, 5};
    std::vector<int> dest(src.size());
    auto pivot = std::find(src.begin(), src.end(), 3);
 
    std::rotate_copy(src.begin(), pivot, src.end(), dest.begin());
    for (int i : dest)
        std::cout << i << ' ';
    std::cout << '\n';
 
    // copy the rotation result directly to the std::cout
    pivot = std::find(dest.begin(), dest.end(), 1);
    std::rotate_copy(dest.begin(), pivot, dest.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
}