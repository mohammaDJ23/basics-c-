#include <iostream>

int main()
{
  char option {};

  do {
    std::cout << "-------------------------------" << std::endl;
    std::cout << "1. This is one." << std::endl;
    std::cout << "2. This is two." << std::endl;
    std::cout << "3. This is three." << std::endl;
    std::cout << "Q. Quit." << std::endl << std::endl;

    std::cout << "Enter an option: ";
    std::cin >> option;

    if (option == '1')
      std::cout << "You chose 1 - " << "This is one." << std::endl;
    else if (option == '2')
      std::cout << "You chose 2 - " << "This is two." << std::endl;
    else if (option == '3')
      std::cout << "You chose 3 - " << "This is three." << std::endl;
    else if (option != 'Q' && option != 'q')
      std::cout << option << " is an unknown option." << std::endl;
    else
      std::cout << "Goodbye..." << std::endl;
  } while (option != 'Q' && option != 'q');

  return 0;
}
