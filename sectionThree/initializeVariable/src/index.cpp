/*
  the initialization of a variable:

  int age; // uninitialize
  int age = 21; // c-like initialization
  int age (21); // constructor initialization
  int age {0}; // c++11 list initialization syntax
*/

#include <iostream>

int main()
{
  std::cout << "Enter the width of the room: ";
  int roomWidth {0};
  std::cin >> roomWidth;

  std::cout << "Enter the length of the room: ";
  int roomLength {0};
  std::cin >> roomLength;

  std::cout << "The are of this room is" << " " << roomWidth * roomLength << " " << "square feet." << std::endl;

  return 0;
}
