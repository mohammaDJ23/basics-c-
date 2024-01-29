#include <iostream>

int main()
{
  int num1 {200};
  int num2 {100};

  int result {0};

  result = num1 + num2;
  std::cout << num1 << " + " << num2 << " = " << result << std::endl;

  result = num1 - num2;
  std::cout << num1 << " - " << num2 << " = " << result << std::endl;

  result = num1 / num2;
  std::cout << num1 << " / " << num2 << " = " << result << std::endl;

  result = num1 * num2;
  std::cout << num1 << " * " << num2 << " = " << result << std::endl;

  result = num1 % num2;
  std::cout << num1 << " % " << num2 << " = " << result << std::endl;

  result = (num1 * num2) - num1;
  std::cout << "(" << num1 << " * " << num2 << ")" << " - " << num1 << " = " << result << std::endl;

  std::cout << "5 / 10" << " = " << 5 / 10 << ", as an int type." << std::endl;
  std::cout << "5.0 / 10.0" << " = " << 5.0 / 10.0 << ", as a double type." << std::endl;

  return 0;
}
