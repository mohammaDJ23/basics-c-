#include <iostream>

#define SQUARE(a) ((a) * (a))
#define MAX(a, b) ((a > b) ? a : b)

#define MAX_SIZE 200

int main()
{
    int num {5};
    double num2 {10.5};
    char c {'a'};
    char c2 {'A'};

    std::cout << SQUARE(num) << std::endl;

    // the result of this calculation will be 100. you have to wrap inside a parenthesis
    // ((5) * (5))
    std::cout << 100 / num * num << std::endl;
    
    std::cout << 100 / SQUARE(num) << std::endl;
    std::cout << SQUARE(num2) << std::endl;
    std::cout << MAX(c, c2) << std::endl;
    std::cout << MAX(num, num2) << std::endl;
    std::cout << MAX_SIZE << std::endl;

    return 0;
}
