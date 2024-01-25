/*

  if you are assiging some variables with different type you get an error.

  int x {0};
  char y {'w'};

  int = y; // error

*/

#include <iostream>

int main()
{
  int num1 {10};
  int num2 {20};

  std::cout << "Num1 is: " << num1 << std::endl;
  std::cout << "Num2 is: " << num2 << std::endl;

  num1 = num2 = 30;

  std::cout << "Num1 is: " << num1 << std::endl;
  std::cout << "Num2 is: " << num2 << std::endl;

  num1 = 10;

  std::cout << "Num1 is: " << num1 << std::endl;

  return 0;
}
