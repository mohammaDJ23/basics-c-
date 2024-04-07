#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cctype>
#include <deque>
#include <algorithm>

template<typename T>
void display(const std::deque<T>& dec)
{
    std::cout << "[ ";
    for (const auto& item : dec)
        std::cout << item << " ";
    std::cout << "]" << std::endl;
}

bool is_palindrome(std::string str)
{
    std::deque<char> dec;

    for (auto c : str)
        if (std::isalpha(c))
            dec.push_back(std::toupper(c));

    while (dec.size() > 1)
    {
        if (dec.front() == dec.back())
        {
            dec.pop_front();
            dec.pop_back();
        }
        else
            return false;
    }

    return true;
}

int main()
{
    std::vector<std::string> vec {"a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome"};

    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for (const auto& str : vec)
        std::cout << std::setw(8) << std::left << is_palindrome(str) << str << std::endl;
    
    return 0;
}
