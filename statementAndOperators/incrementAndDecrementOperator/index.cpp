/*

  never use this operator (++) for a same variable in one statement.
  example:

  std::cout << ++counter << " " << counter++ << std::endl;

*/

#include <iostream>

int main()
{
  int counter {10};
  int result {0};

  std::cout << "result = " << result << "; counter = " << counter << "." << std::endl;

  result = ++counter + 10;
  std::cout << "result = ++counter + 10 will be " << result << std::endl;

  return 0;
}
