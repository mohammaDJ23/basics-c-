#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

struct Square_Functor
{
    void operator()(int i) 
    { 
        std::cout << i * i << " "; 
    }
};

template <typename T>
struct Displayer
{
    void operator()(const T &data) 
    { 
        std::cout << data << " "; 
    }
};

class Multiplier
{
private:
    int num {};

public:
    Multiplier(int n) : num(n) {}
    
    int operator()(int n) const
    {
        return n * num;
    }
};

int main()
{
    std::cout << "test1============================" << std::endl;
    
    Square_Functor square;
    square(4);

    Displayer<int> d1;
    Displayer<std::string> d2;
    d1(100);
    d2("Mike");

    std::cout << std::endl << std::endl << "test2============================" << std::endl;

    std::vector<int> vec1 {1, 2, 3, 4, 5};
    std::vector<std::string> vec2 {"Larry", "Moe", "Curly"};
    
    std::for_each(vec1.begin(), vec1.end(), square);
    std::cout << std::endl;

    std::for_each(vec1.begin(), vec1.end(), Displayer<int>());
    std::cout << std::endl;

    std::for_each(vec1.begin(), vec1.end(), d1);
    std::cout << std::endl;

    std::for_each(vec2.begin(), vec2.end(), Displayer<std::string>());
    std::cout << std::endl;

    std::for_each(vec2.begin(), vec2.end(), d2);
    std::cout << std::endl;

    std::cout << std::endl << "test3============================" << std::endl;

    std::for_each(vec1.begin(), vec1.end(), 
        [] (int i) { std::cout << i * i << " "; });
    std::cout << std::endl;

    std::for_each(vec1.begin(), vec1.end(), 
        [] (int i) { std::cout << i * 10 << " "; });
    std::cout << std::endl;

    std::for_each(vec1.begin(), vec1.end(), 
        [] (int i) { std::cout << i << " "; });
    std::cout << std::endl;

    std::for_each(vec2.begin(), vec2.end(), 
        [] (std::string s) { std::cout << s << " "; });
    std::cout << std::endl;

    std::cout << std::endl << "test4============================" << std::endl;

    Multiplier mult (100);

    vec1 = {1, 2, 3, 4, 5};
    std::transform(vec1.begin(), vec1.end(), vec1.begin(), mult);
    std::for_each(vec1.begin(), vec1.end(), d1);
    std::cout << std::endl;

    vec1 = {1, 2, 3, 4, 5};
    std::transform(vec1.begin(), vec1.end(), vec1.begin(),
        [] (int i) { return i * 100; });
    std::for_each(vec1.begin(), vec1.end(),
        [] (int i) { std::cout << i << " "; });
    std::cout << std::endl;

    return 0;
}
