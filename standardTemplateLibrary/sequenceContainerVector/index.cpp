/*

    The elements are stored contiguously, which means that elements can be accessed not only through iterators, 
    but also using offsets to regular pointers to elements. 
    This means that a pointer to an element of a vector may be passed to any function that 
    expects a pointer to an element of an array.

    The storage of the vector is handled automatically, being expanded as needed. 
    Vectors usually occupy more space than static arrays, because more memory is allocated to handle future growth. 
    This way a vector does not need to reallocate each time an element is inserted, 
    but only when the additional memory is exhausted. 
    The total amount of allocated memory can be queried using capacity() function. 
    Extra memory can be returned to the system via a call to shrink_to_fit()[1].

    Reallocations are usually costly operations in terms of performance. 
    The reserve() function can be used to eliminate reallocations if the number of elements is known beforehand.

    The complexity (efficiency) of common operations on vectors is as follows:

    Random access - constant 𝓞(1).
    Insertion or removal of elements at the end - amortized constant 𝓞(1).
    Insertion or removal of elements - linear in the distance to the end of the vector 𝓞(n).

    std::vector (for T other than bool) meets the requirements of Container, 
    AllocatorAwareContainer(since C++11), SequenceContainer, ContiguousContainer(since C++17) and ReversibleContainer.

    Member functions of std::vector are constexpr: 
    it is possible to create and use std::vector objects in the evaluation of a constant expression.

    However, std::vector objects generally cannot be constexpr, 
    because any dynamically allocated storage must be released in the same evaluation of constant expression.
    
*/

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

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
void display(const std::vector<T>& vec)
{
    std::cout << "[ ";
    std::for_each(vec.begin(), vec.end(), 
        [] (const auto& item) { std::cout << item << " "; });
    std::cout << "]" << std::endl;
}

void test1()
{
    std::cout << std::endl << "test1=========================" << std::endl;

    std::vector<int> vec {1, 2, 3, 4, 5};
    display(vec);
    vec = {6, 7, 8, 9, 10};
    display(vec);
    std::vector<int> vec1 (10, 100);
    display(vec1);

    std::cout << std::endl;
}

void test2()
{
    std::cout << std::endl << "test2=========================" << std::endl;

    std::vector<int> vec {1, 2, 3, 4, 5};

    display(vec);
    std::cout << "vec size: " << vec.size() << std::endl;
    std::cout << "vec capacity: " << vec.capacity() << std::endl; // capacity is the size of the allocated storage space
    std::cout << "vec max_size: " << vec.max_size() << std::endl;

    vec.push_back(6);
    display(vec);
    std::cout << "vec size: " << vec.size() << std::endl;
    std::cout << "vec capacity: " << vec.capacity() << std::endl; // after push_back, capacity will be double at most of the time
    std::cout << "vec max_size: " << vec.max_size() << std::endl;

    vec.shrink_to_fit(); // c++11. this will shrink the allocated storage as shown in capacity when you do push_back to the vector size
    display(vec);
    std::cout << "vec size: " << vec.size() << std::endl;
    std::cout << "vec capacity: " << vec.capacity() << std::endl;
    std::cout << "vec max_size: " << vec.max_size() << std::endl;

    vec.reserve(100); // this will reserve 100 space for the vector and now capacity is 100 and when the capacity exceed 100, again it will be double
    display(vec);
    std::cout << "vec size: " << vec.size() << std::endl;
    std::cout << "vec capacity: " << vec.capacity() << std::endl;
    std::cout << "vec max_size: " << vec.max_size() << std::endl;

    std::cout << std::endl;
}

void test3()
{
    std::cout << std::endl << "test3=========================" << std::endl;

    std::vector<int> vec {1, 2, 3, 4, 5};

    display(vec);
    
    vec[0] = 100; // no bounce checking
    vec.at(1) = 200; // bounce checking

    display(vec);

    std::cout << std::endl;
}

void test4()
{
    std::cout << std::endl << "test4=========================" << std::endl;

    std::vector<Person> stooges;
    display(stooges);

    Person p1 {"Jack", 20};
    stooges.push_back(p1);
    display(stooges);
    
    stooges.push_back(Person {"Moe", 40});
    display(stooges);

    stooges.emplace_back("Curly", 30);
    display(stooges);

    std::cout << std::endl;
}

void test5()
{
    std::cout << std::endl << "test5=========================" << std::endl;

    std::vector<Person> stooges
    {
        {"Larry", 18},
        {"Moe", 25},
        {"Curly", 30}
    };

    display(stooges);
    std::cout << "front: " << stooges.front() << std::endl;
    std::cout << "back: " << stooges.back() << std::endl;

    stooges.pop_back();
    display(stooges);

    std::cout << std::endl;
}

void test6()
{
    std::cout << std::endl << "test6=========================" << std::endl;

    std::vector<int> vec {1, 2, 3, 4, 5};
    display(vec);

    vec.clear();
    display(vec);

    vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display(vec);
    vec.erase(vec.begin());
    display(vec);
    vec.erase(vec.begin(), vec.begin() + 2);
    display(vec);

    vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto it = vec.begin();
    while (it != vec.end())
    {   
        if (*it % 2 == 0)
            vec.erase(it);
        else
            it++;
    }

    display(vec);

    std::cout << std::endl;
}

void test7()
{
    std::cout << std::endl << "test7=========================" << std::endl;

    std::vector<int> vec1 {1, 2, 3, 4, 5}; // size 5
    std::vector<int> vec2 {10, 20, 30, 40, 50, 60}; // size 6
    
    display(vec1);
    display(vec2);

    vec1.swap(vec2);
    display(vec1);
    display(vec2);

    std::cout << std::endl;
}

void test8()
{
    std::cout << std::endl << "test8=========================" << std::endl;

    std::vector<int> vec {1, 2, 3, 2, 5}; 
    
    std::sort(vec.begin(), vec.end());
    display(vec);

    std::cout << std::endl;
}

void test9()
{
    std::cout << std::endl << "test9=========================" << std::endl;

    std::vector<int> vec1 {1, 2, 3, 2, 5}; 
    std::vector<int> vec2 {10, 20};

    display(vec1);
    display(vec2);

    std::copy(vec1.begin(), vec1.end(), std::back_inserter(vec2));

    display(vec1);
    display(vec2);

    vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
    vec2 = {10, 20};

    std::copy_if(vec1.begin(),
        vec1.end(),
        std::back_inserter(vec2),
        [] (const auto& item) {
            return item % 2 == 0;
        });

    display(vec1);
    display(vec2);

    std::cout << std::endl;
}

void test10()
{
    std::cout << std::endl << "test10=========================" << std::endl;

    std::vector<int> vec1 {1, 2, 3, 4, 5}; // size 5
    std::vector<int> vec2 {10, 20, 30, 40, 50, 60}; // size 6
    std::vector<int> vec3;
    
    std::transform(vec1.begin(),
        vec1.end(),
        vec2.begin(),
        std::back_inserter(vec3),
        [] (const auto& item1, const auto& item2) {
            return item1 * item2;
        });

    display(vec3);

    std::cout << std::endl;
}

void test11()
{
    std::cout << std::endl << "test11=========================" << std::endl;

    std::vector<int> vec1 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> vec2 {100, 200, 300, 400};
    
    auto it = std::find(vec1.begin(), vec1.end(), 5);

    if (it != vec1.end())
    {
        std::cout << "inserting..." << std::endl;
        vec1.insert(it, vec2.begin(), vec2.end());
    }
    else
        std::cout << "Sorry, 5 not found" << std::endl;

    display(vec1);

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
    test10();
    test11();
    
    return 0;
}
