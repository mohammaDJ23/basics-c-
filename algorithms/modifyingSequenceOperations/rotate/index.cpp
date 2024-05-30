#include <algorithm>
#include <iostream>
#include <vector>

template<class ForwardIt>
constexpr // since C++20
ForwardIt rotate(ForwardIt first, ForwardIt middle, ForwardIt last)
{
    if (first == middle)
        return last;
 
    if (middle == last)
        return first;
 
    ForwardIt write = first;
    ForwardIt next_read = first; // read position for when “read” hits “last”
 
    for (ForwardIt read = middle; read != last; ++write, ++read)
    {
        if (write == next_read)
            next_read = read; // track where “first” went
        std::iter_swap(write, read);
    }
 
    // rotate the remaining sequence into place
    rotate(write, next_read, last);
    return write;
}
 
auto print = [](const auto remark, const auto& v)
{
    std::cout << remark;
    for (auto n : v)
        std::cout << n << ' ';
    std::cout << '\n';
};
 
int main()
{
    std::vector<int> v{2, 4, 2, 0, 5, 10, 7, 3, 7, 1};
    print("before sort:\t\t", v);
 
    // insertion sort
    for (auto i = v.begin(); i != v.end(); ++i)
        std::rotate(std::upper_bound(v.begin(), i, *i), i, i + 1);
    print("after sort:\t\t", v);
 
    // simple rotation to the left
    std::rotate(v.begin(), v.begin() + 1, v.end());
    print("simple rotate left:\t", v);
 
    // simple rotation to the right
    std::rotate(v.rbegin(), v.rbegin() + 1, v.rend());
    print("simple rotate right:\t", v);
}