#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>

void print_menu(void);
void print_numbers(const std::vector<int> &numbers);
void add_number(std::vector<int> &numbers);
void print_mean_of_numbers(const std::vector<int> &numbers);
void print_smallet_number(const std::vector<int> &numbers);
void print_larget_number(const std::vector<int> &numbers);
void clear_list(std::vector<int> &numbers);
bool is_app_running(char &option);
char get_option(void);
void default_option(char option);
void quit(void);
void print_list(const std::vector<int> &numbers);
double calc_mean(const std::vector<int> &numbers);

void print_menu(void)
{
  std::cout << "P. print numbers" << std::endl;
  std::cout << "A. add a number" << std::endl;
  std::cout << "M. display mean of the numbers" << std::endl;
  std::cout << "S. display the smallest number" << std::endl;
  std::cout << "L. display the largest number" << std::endl;
  std::cout << "C. clear the list" << std::endl;
  std::cout << "Q. quit" << std::endl << std::endl;
}

void print_list(const std::vector<int> &numbers)
{
  std::cout << "[ ";

  for (auto number : numbers)
    std::cout << number << " ";
  
  std::cout << "]" << std::endl;
}

void print_numbers(const std::vector<int> &numbers)
{
  if (!static_cast<bool>(numbers.size()))
    std::cout << "[] - This list is empty." << std::endl;
  else
    print_list(numbers);
}

void add_number(std::vector<int> &numbers)
{
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
}

double calc_mean(const std::vector<int> &numbers)
{
  int mean {};

  for (auto number : numbers)
    mean += number;

  return static_cast<double>(mean) / numbers.size();
}

void print_mean_of_numbers(const std::vector<int> &numbers)
{
  if (!static_cast<bool>(numbers.size()))
    std::cout << "[] - This list is empty and could not find the mean." << std::endl;
  else {
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "The mean is " << calc_mean(numbers) << std::endl;
  }
}

void print_smallet_number(const std::vector<int> &numbers)
{
  if (!static_cast<bool>(numbers.size()))
    std::cout << "[] - This list is empty and could not find the smallest." << std::endl;
  else {
    int smallest {INT_MAX};

    for (auto number : numbers)
      if (number < smallest)
        smallest = number;

    std::cout << "The smallest is " << smallest << std::endl;
  }
}

void print_larget_number(const std::vector<int> &numbers)
{
  if (!static_cast<bool>(numbers.size()))
    std::cout << "[] - This list is empty and could not find the largest." << std::endl;
  else {
    int largest {INT_MIN};

    for (auto number : numbers)
      if (number > largest)
        largest = number;

    std::cout << "The largest is " << largest << std::endl;
  }
}

void clear_list(std::vector<int> &numbers)
{
  numbers.clear();
  std::cout << "He list was cleared." << std::endl;
}

bool is_app_running(char &option)
{
  return option != 'Q';
}

char get_option(void)
{
  char option {};
  std::cout << "Enter the option: ";
  std::cin >> option;
  return toupper(option);
}

void default_option(char option)
{
  std::cout << option << " is unknown, please try again." << std::endl;
}

void quit(void)
{
  std::cout << "Goodbye..." << std::endl;
}

int main()
{
  std::vector<int> numbers;
  char option {};

  do {
    print_menu();

    option = get_option();

    switch (option) {
      case 'P': 
        print_numbers(numbers);
        break;

      case 'A': 
        add_number(numbers);
        break;

      case 'M': 
        print_mean_of_numbers(numbers);
        break;

      case 'S': 
        print_smallet_number(numbers);
        break;

      case 'L':
        print_larget_number(numbers);
        break;

      case 'C': 
        clear_list(numbers);
        break;

      case 'Q': 
        quit();
        break;

      default: 
        default_option(option);
        break;
    }

    std::cout << std::endl << std::endl;
  } while (is_app_running(option));

  return 0;
}
