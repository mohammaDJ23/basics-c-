/*

    - the default percision is 6 and it does not matter the numbers before or after point.
    it will counts from left before point.

    - if the numbers before the point were more than 6, it will use the scientific format.

*/

#include <iostream>
#include <iomanip>

int main()
{
    double num1 {123456789.987654321};
    double num2 {1234.5678};
    double num3 {1234.0};

    std::cout << "Defaults ==========================" << std::endl;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;

    std::cout << "Percision 2 ==========================" << std::endl;
    std::cout << std::setprecision(2);
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;

    std::cout << "Percision 5 ==========================" << std::endl;
    std::cout << std::setprecision(5);
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;

    std::cout << "Percision 5 ==========================" << std::endl;
    std::cout << std::setprecision(5);
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;

    std::cout << "Percision 9 ==========================" << std::endl;
    std::cout << std::setprecision(9);
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;

    std::cout << "Percision 3 - fixed ==========================" << std::endl;
    std::cout << std::setprecision(3) << std::fixed;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;

    std::cout << "Percision 3 - fixed - scientific - uppercase - showpos ==========================" << std::endl;
    std::cout << std::setprecision(3) << std::scientific << std::uppercase << std::showpos;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;

    // back to defaults (both of the are equal)
    std::cout.unsetf(std::ios::scientific | std::ios::fixed);
    std::cout << std::resetiosflags(std::ios::showpos);

    std::cout << "Percision 10 - showpoint ==========================" << std::endl;
    std::cout << std::setprecision(10) << std::showpoint;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;

    // back to default
    std::cout.unsetf(std::ios::scientific | std::ios::fixed);
    std::cout << std::setprecision(6);
    std::cout << std::resetiosflags(std::ios::showpoint);
    std::cout << std::resetiosflags(std::ios::showpos);

    std::cout << "Back to defaults ==========================" << std::endl;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;

    return 0;
}
