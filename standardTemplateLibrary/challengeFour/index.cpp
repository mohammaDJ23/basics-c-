#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cctype>
#include <algorithm>
#include <stack>
#include <queue>

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
    std::stack<char> s;
    std::queue<char> q;
    char temp_c {};
    
    for (const auto& c : str)
    {
        if (std::isalpha(c))
        {
            temp_c = std::toupper(c);
            s.push(temp_c);
            q.push(temp_c);
        }   
    }

    while (!s.empty() && !q.empty())
    {
        if (s.top() != q.front())
            return false;

        s.pop();
        q.pop();
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
