#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

template<class InputIt, class OutputIt>
OutputIt copy(InputIt first, InputIt last, OutputIt d_first)
{
    for (; first != last; (void)++first, (void)++d_first)
        *d_first = *first;
 
    return d_first;
}
 
int main()
{
    std::vector<int> from_vector(10);
    std::iota(from_vector.begin(), from_vector.end(), 0);
 
    std::vector<int> to_vector;
    std::copy(from_vector.begin(), from_vector.end(), std::back_inserter(to_vector));
    // or, alternatively,
    //  std::vector<int> to_vector(from_vector.size());
    //  std::copy(from_vector.begin(), from_vector.end(), to_vector.begin());
    // either way is equivalent to
    //  std::vector<int> to_vector = from_vector;
 
    std::cout << "to_vector contains: ";
 
    std::copy(to_vector.begin(), to_vector.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
 
    for (const int x : to_vector)
        std::cout << x << ' ';
    std::cout << '\n';
}