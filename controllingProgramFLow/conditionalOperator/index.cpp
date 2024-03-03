#include <iostream>

int main()
{
  int num1 {}, num2 {};

  std::cout << "Enter two integer: ";
  std::cin >> num1 >> num2;

  if (num1 == num2)
    std::cout << "The numbers are equal." << std::endl;
  else {
    std::cout << "Largest " << (num1 > num2 ? num1 : num2) << std::endl;
    std::cout << "Smallest " << (num1 < num2 ? num1 : num2) << std::endl;
  }

  return 0;
}
