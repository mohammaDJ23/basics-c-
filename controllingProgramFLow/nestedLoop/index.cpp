#include <iostream>
#include <vector>

int main()
{
  std::vector<int> numbers;
  int num {};
  int current_data_item {};

  std::cout << "How many data item do you have? ";
  std::cin >> num;

  for (int i = 0; i < num; i++) {
    std::cout << "Enter data item: ";
    std::cin >> current_data_item;

    numbers.push_back(current_data_item);
  }

  for (auto number : numbers) {
    for (int i = 1; i <= number; i++)
      std::cout << "-";

    std::cout << std::endl;
  }

  return 0;
}
