/*

    list
        std::list is a container that supports constant time insertion and removal of elements from 
        anywhere in the container. Fast random access is not supported. 
        It is usually implemented as a doubly-linked list. 
        Compared to std::forward_list this container provides bidirectional iteration capability while 
        being less space efficient.

        Adding, removing and moving the elements within the list or across several lists does not 
        invalidate the iterators or references. 
        An iterator is invalidated only when the corresponding element is deleted.

        std::list meets the requirements of Container, AllocatorAwareContainer, SequenceContainer and ReversibleContainer.

    forward_list
        std::forward_list is a container that supports fast insertion and 
        removal of elements from anywhere in the container. Fast random access is not supported. 
        It is implemented as a singly-linked list. 
        Compared to std::list this container provides more space efficient storage when 
        bidirectional iteration is not needed.

        Adding, removing and moving the elements within the list, or across several lists, 
        does not invalidate the iterators currently referring to other elements in the list. 
        However, an iterator or reference referring to an element is invalidated when 
        the corresponding element is removed (via erase_after) from the list.

        std::forward_list meets the requirements of Container (except for the size member function and 
        that operator=='s complexity is always linear), AllocatorAwareContainer and SequenceContainer.
*/

#include <iostream>
#include <list>
#include <forward_list>
#include <string>
#include <algorithm>
#include <iterator>

class Person
{
    friend std::ostream& operator<<(std::ostream& os, const Person& p);
private:
    std::string name;
    int age;

public:
    Person() : name("Unknown"), age(0) {};
    Person(std::string name, int age) : name(name), age(age) {}

    bool operator<(const Person& rhs) const { return this->age < rhs.age; }
    bool operator==(const Person& rhs) const { return this->name == rhs.name && this->age == rhs.age; }
};

std::ostream& operator<<(std::ostream& os, const Person& p)
{
    os << p.name << ":" << p.age;
    return os;
}

template <typename T>
void display(const std::list<T>& list)
{
    std::cout << "[ ";
    for (const auto& item : list)
        std::cout << item << " ";
    std::cout << "]" << std::endl;
}

template <typename T>
void display(const std::forward_list<T>& list)
{
    std::cout << "[ ";
    for (const auto& item : list)
        std::cout << item << " ";
    std::cout << "]" << std::endl;
}

void test1()
{
    std::cout << std::endl << "test1============================" << std::endl;

    std::forward_list<int> fl {1, 2, 3, 4, 5};
    display(fl);

    std::cout << "max_size: " << fl.max_size() << std::endl;
    std::cout << "front: " << fl.front() << std::endl;

    std::cout << std::endl;
}

void test2()
{
    std::cout << std::endl << "test2============================" << std::endl;

    std::forward_list<Person> fl;
    display(fl);

    Person p1 {"Larry", 18};

    fl.push_front(p1);
    std::cout << "front: " << fl.front() << std::endl;

    fl.pop_front();
    fl.emplace_front("Jack", 19);
    display(fl);

    std::cout << std::endl;
}

void test3()
{
    std::cout << std::endl << "test3============================" << std::endl;

    std::forward_list<int> fl {1, 2, 3, 4, 5};
    display(fl);

    auto it = std::find(fl.begin(), fl.end(), 3);
    if (it != fl.end())
    {
        fl.insert_after(it, 10);
        fl.emplace_after(it, 100);
    }
    display(fl);

    fl.erase_after(it);
    display(fl);

    fl.resize(2);
    display(fl);

    fl.resize(5);
    display(fl);

    std::cout << std::endl;
}

void test4()
{
    std::cout << std::endl << "test4============================" << std::endl;

    std::list<int> l {1, 2, 3, 4, 5};
    display(l);

    std::list<std::string> l2;
    l2.push_back("Back");
    l2.push_front("Front");
    display(l2);

    std::list<int> l3;
    l3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display(l3);

    std::list l4 (10, 100);
    display(l4);

    std::cout << std::endl;
}

void test5()
{
    std::cout << std::endl << "test5============================" << std::endl;

    std::list<int> l {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display(l);

    std::cout << "size: " << l.size() << std::endl;
    std::cout << "front: " << l.front() << std::endl;
    std::cout << "back: " << l.back() << std::endl;

    l.clear();
    display(l);
    std::cout << "size: " << l.size() << std::endl;

    std::cout << std::endl;
}

void test6()
{
    std::cout << std::endl << "test6============================" << std::endl;

    std::list<int> l {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display(l);

    l.resize(5);
    display(l);

    l.resize(10);
    display(l);

    std::list<Person> lp;
    lp.resize(5);
    display(lp);

    std::cout << std::endl;
}

void test7()
{
    std::cout << std::endl << "test7============================" << std::endl;

    std::list<int> l {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display(l);

    auto it = std::find(l.begin(), l.end(), 5);
    if (it != l.end())
        l.insert(it, 100);
    display(l);

    std::list l2 {1000, 2000, 3000};
    l.insert(it, l2.begin(), l2.end());
    display(l);

    std::advance(it, -4);
    std::cout << *it << std::endl;

    l.erase(it);
    display(l);

    std::cout << std::endl;
}

void test8()
{
    std::cout << std::endl << "test8============================" << std::endl;

    std::list<Person> stooges
    {
        {"Larry", 18},
        {"Moe", 25},
        {"Curly", 17}
    };
    display(stooges);

    std::string name;
    int age {};

    std::cout << "Enter the name of the next stooge: ";
    std::getline(std::cin, name);
    std::cout << "Enter their age: ";
    std::cin >> age;

    stooges.emplace_back(name, age);
    display(stooges);

    auto it = std::find(stooges.begin(), stooges.end(), Person {"Moe", 25});
    if (it != stooges.end())
        stooges.emplace(it, "Frank", 18);
    display(stooges);

    std::cout << std::endl;
}

void test9()
{
    std::cout << std::endl << "test9============================" << std::endl;

    std::list<Person> stooges
    {
        {"Larry", 18},
        {"Moe", 25},
        {"Curly", 17}
    };
    display(stooges);

    stooges.sort();
    display(stooges);

    std::cout << std::endl;
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
    test8();
    test9();
    
    return 0;
}
