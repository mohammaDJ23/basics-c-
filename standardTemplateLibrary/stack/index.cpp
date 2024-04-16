#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <list>

template <typename T>
void display(std::stack<T> s)
{
    std::cout << "[ ";
    while (!s.empty())
    {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << "]" << std::endl;
}

int main()
{
    std::stack<int> s; // by default it use deque
    std::stack<int, std::vector<int>> s1; // vector
    std::stack<int, std::list<int>> s2; // list
    std::stack<int, std::deque<int>> s3; // deque

    for (const auto& i : {1, 2, 3, 4})
        s.push(i);
    display(s);

    s.push(100);
    display(s);

    s.pop();
    s.pop();
    display(s);

    while (!s.empty())
        s.pop();
    display(s);

    s.push(10);
    display(s);

    s.top() = 100;
    display(s);
    
    return 0;
}
