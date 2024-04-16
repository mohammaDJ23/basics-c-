#include <iostream>
#include <queue>

class Person final
{
    friend std::ostream& operator<<(std::ostream& os, const Person& p);

private:
    std::string name;
    int age;

public:
    Person() = default;
    Person(std::string name, int age) : name(name), age(age) {}

    bool operator<(const Person& rhs) const
    {
        return this->age < rhs.age;
    }

    bool operator==(const Person& rhs) const
    {
        return this->name == rhs.name && this->age && rhs.age;
    }
};

std::ostream& operator<<(std::ostream& os, const Person& p)
{
    os << p.name << ":" << p.age;
    return os;
}

template <typename T>
void display(std::priority_queue<T> pq)
{
    std::cout << std::endl;
    while (!pq.empty())
    {
        std::cout << "| " << pq.top() << std::endl;
        pq.pop();
    }
    std::cout << std::endl;
}

void test1()
{
    std::cout << std::endl << "test1=========================" << std::endl;

    std::priority_queue<int> pq;
    for (const auto& i : {3, 12, 0, 20, 44, 2, 100, 39})
        pq.push(i);
    
    std::cout << "size: " << pq.size() << std::endl;
    std::cout << "top: " << pq.top() << std::endl;
    display(pq);

    pq.pop();
    display(pq);

    std::cout << std::endl;
}

void test2()
{
    std::cout << std::endl << "test2=========================" << std::endl;

    std::priority_queue<Person> pq;
    
    pq.push(Person {"A", 10});
    pq.push(Person {"B", 1});
    pq.push(Person {"C", 14});
    pq.push(Person {"D", 18});
    pq.push(Person {"E", 7});
    pq.push(Person {"F", 27});

    display(pq);

    std::cout << std::endl;
}

int main()
{
    test1();
    test2();
    
    return 0;
}
