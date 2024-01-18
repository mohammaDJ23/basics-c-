#include <iostream>

int main()
{
  std::cout << "Hello, welcome to jack's carpet cleaning service" << std::endl << std::endl;
  std::cout << "How many rooms would you like cleaned? ";

  int numbers_of_rooms {0};
  std::cin >> numbers_of_rooms;

  const double price_per_room {32.5};
  const double sales_tax {0.06};
  const int estimate_expiry {30}; // days

  std::cout << std::endl << "Estimate for carpet cleaning service" << std::endl;
  std::cout << "The numebr of rooms: " << numbers_of_rooms << std::endl;
  std::cout << "The price per room: $" << price_per_room << std::endl;
  std::cout << "The cost: $" << price_per_room * numbers_of_rooms << std::endl;
  std::cout << "The tax: $" << price_per_room * numbers_of_rooms * sales_tax << std::endl;
  std::cout << "***************************************" << std::endl;
  std::cout << "The total estimate: $" << (price_per_room * numbers_of_rooms) + (price_per_room * numbers_of_rooms * sales_tax) << std::endl;
  std::cout << "This estimate is valid for " << estimate_expiry << std::endl;

  return 0;
}
