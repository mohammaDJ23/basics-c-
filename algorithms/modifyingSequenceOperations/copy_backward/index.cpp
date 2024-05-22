#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

template<class BidirIt1, class BidirIt2>
BidirIt2 copy_backward(BidirIt1 first, BidirIt1 last, BidirIt2 d_last)
{
    while (first != last)
        *(--d_last) = *(--last);
    
    return d_last;
}
 
int main()
{
    std::vector<int> source(4);
    std::iota(source.begin(), source.end(), 1); // fills with 1, 2, 3, 4
 
    std::vector<int> destination(6);
 
    std::copy_backward(source.begin(), source.end(), destination.end());
 
    std::cout << "destination contains: ";
    for (auto i: destination)
        std::cout << i << ' ';
    std::cout << '\n';
}