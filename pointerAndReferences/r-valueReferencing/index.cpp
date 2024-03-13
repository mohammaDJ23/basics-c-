/*

  as the compiler creates a temp storage for r-value and it's not in the reguler variable,
  if you decide to access to it, you have to use && sign.
  see the example below.

*/

#include <iostream>
#include <vector>
#include <string>

void print(int &n)
{
  std::cout << &n << std::endl;
  std::cout << "the value of n, with l-value reference, is: " << n << std::endl;
}

void print(int &&n)
{
  std::cout << "the value of n, with r-value reference, is: " << n << std::endl;
}

int main()
{
  int num1 {10};
  int &num2 {num1};
  int &&num3 {20};

  print(num1); // prints as l-value
  print(num2); // prints as l-value
  print(num3); // prints as l-value
  print(30); // prints as r-value
  print(30 + 10); // prints as r-value

  return 0;
}
