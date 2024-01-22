#include <iostream>

int main()
{
  int numbers [3][4] {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
  };

  std::cout << "The number of index [2][3] is: " << numbers[2][3] << std::endl;

  return 0;
}
