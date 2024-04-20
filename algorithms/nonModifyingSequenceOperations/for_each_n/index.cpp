#include <algorithm>
#include <iostream>
#include <vector>

template<class InputIt, class Size, class UnaryFunc>
InputIt for_each_n(InputIt first, Size n, UnaryFunc f)
{
    for (Size i = 0; i < n; ++first, (void) ++i)
        f(*first);
 
    return first;
}

void println(auto const& v)
{
    for (auto count{v.size()}; const auto& e : v)
        std::cout << e << (--count ? ", " : "\n");
}
 
int main()
{
    std::vector<int> vi{1, 2, 3, 4, 5};
    println(vi);
 
    std::for_each_n(vi.begin(), 3, [](auto& n) { n *= 2; });
    println(vi);
}
