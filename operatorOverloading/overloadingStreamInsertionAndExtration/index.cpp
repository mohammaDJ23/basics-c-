#include <iostream>
#include "String.h"

int main()
{
  String larry {"Larry"};
  String moe {"Moe"};
  String curly;

  std::cout << "Enter the third stooge's first name: ";
  std::cin >> curly;

  std::cout << "The three stooges are " << larry << ", " << moe << " and " << curly << std::endl;

  std::cout << "Enter the three stooges names seperated by an space: ";
  std::cin >> larry >> moe >> curly;

  std::cout << "The three stooges are " << larry << ", " << moe << " and " << curly << std::endl;

  return 0;
}
