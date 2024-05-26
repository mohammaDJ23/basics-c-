#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
 
int main()
{
    std::string s1 {"A string with mmmany letters!"};
    std::cout << "Before: " << s1 << '\n';
 
    std::string s2;
    std::unique_copy(s1.begin(), 
        s1.end(), 
        std::back_inserter(s2),
        [](char c1, char c2) { return c1 == 'm' && 'm' == c2; });
 
    std::cout << "After:  " << s2 << '\n';
}