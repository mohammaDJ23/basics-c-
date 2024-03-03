#include <iostream>
#include <vector>
#include <iomanip>

int main()
{
  std::vector<int> numbers;
  char option {};

  do {
    std::cout << "P. print numbers" << std::endl;
    std::cout << "A. add a number" << std::endl;
    std::cout << "M. display mean of the numbers" << std::endl;
    std::cout << "S. display the smallest number" << std::endl;
    std::cout << "L. display the largest number" << std::endl;
    std::cout << "C. clear the list" << std::endl;
    std::cout << "Q. quit" << std::endl << std::endl;

    std::cout << "Enter the option: ";
    std::cin >> option;

    switch (option) {
      case 'P':
      case 'p': {
        if (!static_cast<bool>(numbers.size()))
          std::cout << "[] - This list is empty." << std::endl;
        else {
          std::cout << "[ ";

          for (auto number : numbers)
            std::cout << number << " ";
          
          std::cout << "]" << std::endl;
        }
        break;
      }

      case 'A':
      case 'a': {
        int num {};
        bool is_num_exist {false};

        std::cout << "Enter an integer: ";
        std::cin >> num;

        for (auto number : numbers)
          is_num_exist = number == num;

        if (is_num_exist)
          std::cout << "The numebr exist before." << std::endl;
        else {
          numbers.push_back(num);
          std::cout << num << " is added." << std::endl;
        }
        break;
      }

      case 'M':
      case 'm': {
        if (!static_cast<bool>(numbers.size()))
          std::cout << "[] - This list is empty and could not find the mean." << std::endl;
        else {
          int mean {};

          for (auto number : numbers)
            mean += number;

          std::cout << std::fixed << std::setprecision(1);
          std::cout << "The mean is " << static_cast<double>(mean) / numbers.size() << std::endl;
        }
        break;
      }

      case 'S':
      case 's': {
        if (!static_cast<bool>(numbers.size()))
          std::cout << "[] - This list is empty and could not find the smallest." << std::endl;
        else {
          int smallest {INT_MAX};

          for (auto number : numbers)
            if (number < smallest)
              smallest = number;

          std::cout << "The smallest is " << smallest << std::endl;
        }
        break;
      }

      case 'L':
      case 'l': {
        if (!static_cast<bool>(numbers.size()))
          std::cout << "[] - This list is empty and could not find the largest." << std::endl;
        else {
          int largest {INT_MIN};

          for (auto number : numbers)
            if (number > largest)
              largest = number;

          std::cout << "The largest is " << largest << std::endl;
        }
        break;
      }

      case 'C':
      case 'c': {
        numbers.clear();
        std::cout << "He list was cleared." << std::endl;
        break;
      }

      case 'Q':
      case 'q': {
        std::cout << "Goodbye..." << std::endl;
        break;
      }

      default: {
        std::cout << option << " is unknown, please try again." << std::endl;
        break;
      }
    }

    std::cout << std::endl << std::endl;
  } while (option != 'Q' && option != 'q');

  return 0;
}
