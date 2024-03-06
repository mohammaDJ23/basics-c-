/*

  sometimes we have very simple function and we suggest to compilter to act it without using extra overhead.
  the overhead occures when a function goes to an stack memory because the memory need to use extra space
  for push, pop, the parameters and return result. so we use inline keyword.

  what in example below happening is:

  int main()
  {
    int result {0};

    result = 10 + 20;

    return 0;
  }

  this will avoid function call overhead.
  but if you use or duplicate inline function so many time it could leads to larger binary.

  the compilter optimizations are very sophisticated and will inline even without your suggestion.
*/

#include <iostream>

inline int add_numbers(int x, int y)
{
  return x + y;
}

int main()
{
  int result {0};

  result = add_numbers(10, 20);

  return 0;
}
