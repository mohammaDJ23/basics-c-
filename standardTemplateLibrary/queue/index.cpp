#include <iostream>
#include <queue>
#include <vector>
#include <list>

template <typename T>
void display(std::queue<T> q)
{
    std::cout << std::endl;
    while (!q.empty())
    {
        std::cout << "| " << q.front() << std::endl;
        q.pop();
    }
    std::cout << std::endl;
}

int main()
{
    std::queue<int> q; // by default it uses deque
    std::queue<int, std::vector<int>> q1; // vector
    std::queue<int, std::list<int>> q2; // list

    for (const auto& i : {1, 2, 3, 4})
        q.push(i);
    display(q);

    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back: " << q.back() << std::endl;

    q.push(100);
    display(q);

    q.pop();
    q.pop();
    display(q);

    while (!q.empty())
        q.pop();
    display(q);
    
    std::cout << "Size: " << q.size() << std::endl;

    q.push(10);
    q.push(100);
    q.push(1000);
    display(q);

    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back: " << q.back() << std::endl;

    q.front() = 5;
    q.back() = 5000;
    display(q);

    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back: " << q.back() << std::endl;
    
    return 0;
}
