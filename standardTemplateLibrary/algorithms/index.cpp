#include <iostream>
#include <cctype>
#include <vector>
#include <list>
#include <algorithm>
#include <string>

class Person
{
private:
    std::string name;
    int age;

public:
    Person() = default;
    Person(std::string name, int age) : name(name), age(age) {}

    bool operator<(const Person& rhs) { return this->age < rhs.age; }
    bool operator==(const Person& rhs) { return this->name == rhs.name && this->age == rhs.age; }
};

void find_test()
{
    std::vector<int> vec {1, 2, 3};
    auto loc = std::find(vec.begin(), vec.end(), 2);
    if (loc != vec.end())
        std::cout << "Found the number: " << *loc << std::endl;
    else
        std::cout << "Could not find the number" << std::endl;

    std::list<Person> players
    {
        Person {"Jack", 20},
        Person {"Moe", 30},
        Person {"James", 40}
    };
    auto loc1 = std::find(std::begin(players), std::end(players), Person {"James", 40});
    if (loc1 != std::end(players))
        std::cout << "James was found" << std::endl;
    else 
        std::cout << "James was not found" << std::endl;
}

void count_test()
{
    std::vector<int> vec {1, 2, 3, 4, 5, 223, 1};
    auto num = std::count(vec.begin(), vec.end(), 1);
    std::cout << num << " occurrences found" << std::endl;
}

void count_if_test()
{
    std::vector<int> vec {1, 2, 5, 6, 8, 2, 5};

    auto num = std::count_if(vec.begin(), vec.end(), [] (const int& x) { return x % 2 == 0; });
    std::cout << num << " even numbers found" << std::endl;

    num = std::count_if(vec.begin(), vec.end(), [] (const int& x) { return x % 2 != 0; });
    std::cout << num << " odd numbers found" << std::endl;

    num = std::count_if(vec.begin(), vec.end(), [] (const int& x) { return x >= 5; });
    std::cout << num << " numbers are >= 5" << std::endl;       
}

void replace_test()
{
    std::vector<int> vec {23, 254, 34, 65, 9, 33, 9};
    
    std::cout << "[ ";
    for (const auto& item : vec)
        std::cout << item << " ";
    std::cout << "]" << std::endl;

    std::replace(vec.begin(), vec.end(), 9, 100);

    std::cout << "[ ";
    for (const auto& item : vec)
        std::cout << item << " ";
    std::cout << "]" << std::endl;
}

void all_of_test()
{
    std::vector<int> vec {2, 4, 6, 7, 2, 54, 99, 45};
    
    if (std::all_of(vec.begin(), vec.end(), [] (const int& x) { return x > 100; }))
        std::cout << "All the elements are > 100";
    else 
        std::cout << "All the element are < 100";
}

void string_transform_test()
{
    std::string str {"Hey this is a test."};

    std::cout << str << std::endl;
    std::transform(str.begin(), str.end(), str.begin(), ::toupper/* ::toupper => (::____) means in global scope */);
    std::cout << str << std::endl;
}

int main()
{
    // find_test();
    // count_test();
    // count_if_test();
    // replace_test();
    // all_of_test();
    // string_transform_test();
    
    return 0;
}
