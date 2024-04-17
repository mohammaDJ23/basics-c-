#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

class Person
{
    friend std::ostream& operator<<(std::ostream& os, const Person& p);

private:
    std::string name;
    int age;

public:
    Person(std::string name, int age) : name(name), age(age) {}
    Person(const Person& p) : name(p.name), age(p.age) {}
    ~Person() = default;

    std::string get_name() const { return this->name; }
    int get_age() const { return this->age; }
    
    void set_name(std::string name) { this->name = name; }
    void set_age(int age) { this->age = age; }
};

std::ostream& operator<<(std::ostream& os, const Person& p)
{
    os << "[Person: " << p.name << " : " << p.age << "]";
    return os;
}

void test1()
{
    std::cout << std::endl << "test1===============" << std::endl;

    [] () { std::cout << "Hi" << std::endl; }();
    [] (int x) { std::cout << x << std::endl; }(100);
    [] (int x, int y) { std::cout << x + y << std::endl; }(100, 200);
}

void test2()
{
    std::cout << std::endl << "test2===============" << std::endl;

    auto l1 = [] () { std::cout << "Hi" << std::endl; };
    l1();

    int num1 {100};
    int num2 {100};

    auto l2 = [] (int x, int y) { std::cout << x + y << std::endl; };
    l2(num1, num2);

    auto l3 =
        [] (int& x, int y)
        {
            std::cout << "x: " << x << " y: " << y << std::endl;
            x = 1000;
            y = 2000;
        };
    l3(num1, num2);
    std::cout << "num1: " << num1 << " num2: " << num2 << std::endl;
}

void test3()
{
    std::cout << std::endl << "test3===============" << std::endl;

    Person stooge {"Larry", 18};
    std::cout << stooge << std::endl;

    auto l4 = 
        [] (Person p) 
        { 
            std::cout << p << std::endl; 
        };
    l4(stooge);

    auto l5 =
        [] (const Person& p)
        {
            std::cout << p << std::endl;
        };  
    l5(stooge);

    auto l6 =
        [] (Person& p)
        {
            p.set_name("Frank");
            p.set_age(25);
            std::cout << p << std::endl;
        };
    l6(stooge);
    std::cout << stooge << std::endl;
}

void filter_vector(const std::vector<int>& vec, 
    std::function<bool(int)> func /* or bool (*func) (int) or auto func */)
{
    std::cout << "[ ";
    for (int i : vec)
        if (func(i))
            std::cout << i << " ";
    std::cout << "]" << std::endl;
}

void test4()
{
    std::cout << std::endl << "test4===============" << std::endl;

    std::vector<int> nums {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    filter_vector(nums, [] (int x) { return x > 50; });
    filter_vector(nums, [] (int x) { return x <= 30; });
    filter_vector(nums, [] (int x) { return x >= 30 && x <= 60; });
}

auto make_lambda()
{
    return [] ()
    {
        std::cout << "This lambda was made using the make_lambda function" << std::endl;
    };
}

void test5()
{
    std::cout << std::endl << "test5===============" << std::endl;

    auto l5 = make_lambda();
    l5();
}

void test6()
{
    std::cout << std::endl << "test6===============" << std::endl;

    auto l6 =
        [] (auto x, auto y)
        {
            std::cout << "x: " << x
                << " y: " << y << std::endl;
        };
    l6(10, 20);
    l6(100.3, 200);
    l6(12.54, 54.88);
    l6(Person("Larry", 18), Person("Curly", 22));
}

void test7()
{
    std::cout << std::endl << "test7===============" << std::endl;

    std::vector<Person> stooges {{"Larry", 18},
        {"Moe", 30}, 
        {"Curly", 25}};

    std::sort(stooges.begin(),
        stooges.end(),
        [] (const Person& p1, const Person& p2)
        {
            return p1.get_name() < p2.get_name();
        });

    std::for_each(stooges.begin(),
        stooges.end(),
        [] (const Person& p)
        {
            std::cout << p << std::endl;
        });

    std::sort(stooges.begin(),
        stooges.end(),
        [] (const Person& p1, const Person& p2)
        {
            return p1.get_age() < p2.get_age();
        });

    std::for_each(stooges.begin(),
        stooges.end(),
        [] (const Person& p)
        {
            std::cout << p << std::endl;
        });
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    
    return 0;
}
