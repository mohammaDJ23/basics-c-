/*

    std::set is an associative container that contains a sorted set of unique objects of type Key. 
    Sorting is done using the key comparison function Compare. 
    Search, removal, and insertion operations have logarithmic complexity. 
    Sets are usually implemented as Red–black trees.

    Everywhere the standard library uses the Compare requirements, 
    uniqueness is determined by using the equivalence relation. 
    In imprecise terms, two objects a and b are considered equivalent if 
    neither compares less than the other: !comp(a, b) && !comp(b, a).

    std::set meets the requirements of Container, AllocatorAwareContainer, AssociativeContainer and ReversibleContainer.

*/

#include <iostream>
#include <set>
#include <string>

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
void display(const std::set<T>& set)
{
    std::cout << "[ ";
    for (const auto& item : set)
        std::cout << item << " ";
    std::cout << "]" << std::endl;
}

void test1()
{
    std::cout << std::endl << "test1==================================" << std::endl;

    std::set<int> s {1, 2, 3, 4, 5};
    display(s);

    s = {2, 2, 4, 4, 6, 8, 10};
    display(s);

    s.insert(3);
    s.insert(1);
    display(s);

    if (s.count(10)) // returns 0 or 1
        std::cout << "10 was found" << std::endl;
    else
        std::cout << "10 was not found" << std::endl;

    auto it = s.find(8);
    if (it != s.end())
        std::cout << *it << " was found" << std::endl;

    s.clear();

    display(s);

    std::cout << std::endl;
}

void test2()
{
    std::cout << std::endl << "test2==================================" << std::endl;

    std::set<Person> s {{"Larry", 10},
        {"Moe", 20},
        {"Jack", 15}};

    display(s);

    s.emplace("James", 50);
    display(s);

    s.emplace("Frank", 50); // NO -- 50 already exist -- operator< is using
    display(s);

    auto it = s.find(Person {"Larry", 10});
    if (it != s.end())
        s.erase(it);
    display(s);

    it = s.find(Person {"XXXX", 20}); // Will remove Moe -- uses operator<
    if (it != s.end())
        s.erase(it);
    display(s);

    std::cout << std::endl;
}

void test3()
{
    std::cout << std::endl << "test3==================================" << std::endl;

    std::set<std::string> s {"A", "B", "C"};
    display(s);

    auto result = s.insert("D"); // std::pair<iterator, bool>
    display(s);

    std::cout << std::boolalpha;
    std::cout << *result.first << std::endl;
    std::cout << result.second << std::endl;

    result = s.insert("A"); // A will not be add and return the iterator of A which is the first one
    display(s);

    std::cout << std::boolalpha;
    std::cout << *result.first << std::endl;
    std::cout << result.second << std::endl;

    std::cout << std::endl;
}

int main()
{
    test1();
    test2();
    test3();
    
    return 0;
}
