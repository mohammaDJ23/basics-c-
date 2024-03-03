#include <iostream>

int main()
{
  int number {0};

  while (number <= 0) {
    std::cout << "Enter an integer more than 0: ";
    std::cin >> number;
  }

  std::cout << "Thanks!" << std::endl << std::endl;

  bool is_done {false};

  while (!is_done) {
    std::cout << "Enter an integer between 1 and 100: ";
    std::cin >> number;

    if (number > 1 && number < 100)
      is_done = true;
  }

  std::cout << "Thanks!" << std::endl << std::endl;
  
  return 0;
}
