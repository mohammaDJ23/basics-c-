#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <array>
#include <algorithm>

void display(const std::array<int, 5>& arr)
{
    std::cout << "[ ";
    for (const auto& item : arr)
        std::cout << item << " ";
    std::cout << "]" << std::endl;
}

void test1()
{
    std::cout << std::endl << "test1=========================" << std::endl;

    std::array<int, 5> arr1 {1, 2, 3, 4, 5}; // double {{  }} if c++11
    std::array<int, 5> arr2;

    display(arr1);
    display(arr2); // elements contain garbage data

    arr2 = {10, 20, 30, 40, 50};

    display(arr1);
    display(arr2);

    std::cout << "Size of arr1 is: " << arr1.size() << std::endl;
    std::cout << "Size of arr2 is: " << arr2.size() << std::endl;

    arr1[0] = 1000; // no out of bound error check
    arr1.at(1) = 2000; // out of bound error check

    display(arr1);

    std::cout << "Front of arr2 is: " << arr2.front() << std::endl;
    std::cout << "Back of arr2 is: " << arr2.back() << std::endl;

    std::cout << std::endl;
}

void test2()
{
    std::cout << std::endl << "test2=========================" << std::endl;

    std::array<int, 5> arr1 {1, 2, 3, 4, 5}; // double {{  }} if c++11
    std::array<int, 5> arr2 {10, 20, 30, 40, 50};

    display(arr1);
    display(arr2);

    arr1.fill(0);

    display(arr1);
    display(arr2);

    arr1.swap(arr2);

    display(arr1);
    display(arr2);

    std::cout << std::endl;
}

void test3()
{
    std::cout << std::endl << "test3=========================" << std::endl;

    std::array<int, 5> arr {1, 2, 3, 4, 5}; // double {{  }} if c++11
    
    int* ptr = arr.data();

    std::cout << ptr << std::endl; // display the first element of the array address (it's the raw pointer)

    std::cout << std::endl;
}

void test4()
{
    std::cout << std::endl << "test4=========================" << std::endl;

    std::array<int, 5> arr {1, 5, 3, 4, 2}; // double {{  }} if c++11
    
    std::sort(arr.begin(), arr.end());

    display(arr);

    std::cout << std::endl;
}

void test5()
{
    std::cout << std::endl << "test5=========================" << std::endl;

    std::array<int, 5> arr {1, 5, 4, 3, 2}; // double {{  }} if c++11
    
    auto min_it = std::min_element(arr.begin(), arr.end());
    auto max_it = std::max_element(arr.begin(), arr.end());
    std::cout << "Min: " << *min_it << " and Max: " << *max_it << std::endl;

    std::cout << std::endl;
}

void test6()
{
    std::cout << std::endl << "test6=========================" << std::endl;

    std::array<int, 5> arr {1, 5, 5, 3, 2}; // double {{  }} if c++11
    
    auto adjacent_it = std::adjacent_find(arr.begin(), arr.end());
    if (adjacent_it != arr.end())
        std::cout << "Adjacent element found with value: " << *adjacent_it << std::endl;
    else    
        std::cout << "No adjacent elements found" << std::endl;

    std::cout << std::endl;
}

void test7()
{
    std::cout << std::endl << "test7=========================" << std::endl;

    std::array<int, 5> arr {1, 5, 5, 3, 2}; // double {{  }} if c++11
    
    auto sum = std::accumulate(arr.begin(), arr.end(), 0);
    std::cout << "Sum of the elements in arr is " << sum << std::endl;

    std::cout << std::endl;
}

void test8()
{
    std::cout << std::endl << "test8=========================" << std::endl;

    std::array<int, 8> arr {1, 5, 5, 3, 2, 5, 5, 3}; // double {{  }} if c++11
    
    auto count = std::count(arr.begin(), arr.end(), 5);
    std::cout << "Found 5: " << count << " times" << std::endl;

    std::cout << std::endl;
}

void test9()
{
    std::cout << std::endl << "test9=========================" << std::endl;

    std::array<int, 8> arr {1, 100, 5, 29, 2, 45, 5, 3}; // double {{  }} if c++11
    
    auto count = std::count_if(arr.begin(), arr.end(), 
        [] (const int& x) {
            return x > 10 && x < 200;
        });
    std::cout << "Found " << count << " matches" << std::endl;

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
