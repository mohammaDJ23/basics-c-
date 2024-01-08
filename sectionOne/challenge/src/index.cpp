/*
  create a c++ program that asks the user for their favorite number
  between 1 and 100. then read this number from the console.

  Suppose the user enters 24.

  then display the following to the console:

  Amazing!! That's my favorite numebr too!
  No really! 24 is my favorite number!
*/

#include <iostream>

int main()
{
  int favorite_number;
  std::cout << "Enter your favorite number between 1 and 100: ";
  std::cin >> favorite_number;
  std::cout << "Amazing!! That's my favorite numebr too!" << std::endl;
  std::cout << "No really!" << " " << favorite_number << " " << "is my favorite number!" << std::endl;
  return 0;
}
