#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>

void display(std::vector<int>& vec)
{
    std::cout << "[ ";
    for (const auto& item : vec)
        std::cout << item << " ";
    std::cout << "]";
}

void test1()
{
    std::vector<int> nums {1, 2, 3, 4, 5};

    auto it = nums.begin();
    std::cout << *it << std::endl;

    it++;
    std::cout << *it << std::endl;

    it += 2;
    std::cout << *it << std::endl;

    it -+ 2;
    std::cout << *it << std::endl;

    it = nums.end() - 1;
    std::cout << *it << std::endl;
}

void test2()
{
    std::vector<int> nums {1, 2, 3, 4, 5};

    std::vector<int>::iterator it = nums.begin();
    while (it != nums.end())
    {
        std::cout << *it << std::endl;
        it++;
    }

    it = nums.begin();
    while (it != nums.end())
    {
        *it = 0;
        it++;
    }

    display(nums);
}


void test3()
{
    std::vector<int> nums {1, 2, 3, 4, 5};

    std::vector<int>::const_iterator it = nums.begin(); // or auto it = nums.cbegin();
    while (it != nums.end())
    {
        std::cout << *it << std::endl;
        it++;   
    }

    it = nums.begin();
    while (it != nums.end())
    {
        // *it = 0; // Compiler error - read only
        it++;
    }
}

void test4()
{
    std::vector<int> vec {1, 2, 3};
    auto it1 = vec.rbegin();
    while (it1 != vec.rend())
    {
        std::cout << *it1 << std::endl;
        it1++;
    }

    std::list<std::string> names {"Larry", "Moe", "Curly"};
    auto it2 = names.crbegin();
    std::cout << *it2 << std::endl;
    it2++;
    std::cout << *it2 << std::endl;

    std::map<std::string, std::string> favorites
    {
        {"Frank", "C++"},
        {"Bill", "Java"},
        {"James", "Javascript"}
    };
    auto it3 = favorites.begin();
    while (it3 != favorites.end())
    {
        std::cout << it3->first << ": " << it3->second << std::endl;
        it3++;
    }
}

void test5()
{
    std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto start = vec.begin();
    auto end = vec.end();
    start += 2;
    end -= 3;

    while (start != end)
    {
        std::cout << *start << std::endl;
        start++;
    }
}

int main()
{
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    
    return 0;
}
