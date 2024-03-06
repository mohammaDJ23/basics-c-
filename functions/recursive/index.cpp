/*

  the fibonacci formula is =>
  F0 = 0
  F1 = 1
  Fn = (Fn − 1) + (Fn − 2)

*/

#include <iostream>

unsigned long long int fibonacci(unsigned long long int n)
{
  if (n <= 1)
    return n;
  return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
  std::cout << fibonacci(10) << std::endl;

  return 0;
}
