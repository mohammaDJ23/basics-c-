#include <iostream>
#include <string>

template <typename T>
T max(T a, T b)
{
    return (a > b) ? a : b;
}

template <typename T>
void print(T arg)
{
    std::cout << arg << std::endl;
}

struct Person
{
    std::string name;
    int age;

    friend std::ostream& operator<<(std::ostream& os, const Person& rhs);

    bool operator>(const Person &rhs) const
    {
        return this->age > rhs.age;
    }
};

std::ostream& operator<<(std::ostream& os, const Person& rhs)
{
    os << rhs.name;
    return os;
}

template <typename T1, typename T2>
void print2(T1 a, T2 b)
{
    std::cout << a << " " << b << std::endl;
}

template <typename T>
void swap(T& a, T&b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    print(max(1, 2));
    print(max('A', 'a'));
    print(max<int>(5, 9));
    print(max<int>(5 + 10, 9));
    print<Person>(max<Person>(Person {"Jack", 10}, Person {"Moe", 20}));

    print2(1, Person {"Larry", 30});
    print2<double, char>(2.44, 'A');

    int a {100};
    int b {200};

    print2(a, b);
    swap(a, b);
    print2(a, b);
    
    return 0;
}
