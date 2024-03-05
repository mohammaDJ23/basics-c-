#include <iostream>
#include <cmath>

int main()
{
  double num {};

  std::cout << "Enter a double: ";
  std::cin >> num;

  std::cout << "The sqrt of " << num << " is " << sqrt(num) << "." << std::endl;
  std::cout << "The cube root of " << num << " is " << cbrt(num) << "." << std::endl;
  std::cout << "The sine of " << num << " is " << sin(num) << "." << std::endl;
  std::cout << "The cosine of " << num << " is " << cos(num) << "." << std::endl;
  std::cout << "The ceil of " << num << " is " << ceil(num) << "." << std::endl;
  std::cout << "The floor of " << num << " is " << floor(num) << "." << std::endl;
  std::cout << "The round of " << num << " is " << round(num) << "." << std::endl;

  return 0;
}
