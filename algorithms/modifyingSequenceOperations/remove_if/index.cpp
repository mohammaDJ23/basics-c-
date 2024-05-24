#include <algorithm>
#include <cassert>
#include <cctype>
#include <complex>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

template<class ForwardIt, class UnaryPred>
ForwardIt remove_if(ForwardIt first, ForwardIt last, UnaryPred p)
{
    first = std::find_if(first, last, p);

    if (first != last)
        for (ForwardIt i = first; ++i != last;)
            if (!p(*i))
                *first++ = std::move(*i);
    
    return first;
}
 
int main()
{
    std::string str2 = "Text\n with\tsome \t  whitespaces\n\n";
    str2.erase(
        std::remove_if(str2.begin(), str2.end(), [](unsigned char x) { return std::isspace(x); }), 
        str2.end());
    std::cout << str2 << '\n';
}