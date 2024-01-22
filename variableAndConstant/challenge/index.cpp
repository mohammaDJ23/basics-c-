#include <iostream>

int main()
{
  std::cout << "Hello, welcome to jack's carpet cleaning service" << std::endl << std::endl;

  std::cout << "How many small rooms would you like cleaned? ";
  int numbers_of_small_rooms {0};
  std::cin >> numbers_of_small_rooms;

  std::cout << "How many large rooms would you like cleaned? ";
  int numbers_of_large_rooms {0};
  std::cin >> numbers_of_large_rooms;

  const double price_per_small_room {25};
  const double price_per_large_room {35};
  const double sales_tax {0.06};
  const int estimate_expiry {30}; // days

  std::cout << std::endl << "Estimate for carpet cleaning service" << std::endl;
  std::cout << "The numebr of small rooms: " << numbers_of_small_rooms << std::endl;
  std::cout << "The numebr of large rooms: " << numbers_of_large_rooms << std::endl;
  std::cout << "The price per small room: $" << price_per_small_room << std::endl;
  std::cout << "The price per large room: $" << price_per_large_room << std::endl;
  std::cout 
    << "The cost: $" 
    << (price_per_small_room * numbers_of_small_rooms) + (price_per_large_room * numbers_of_large_rooms) 
    << std::endl;
  std::cout 
    << "The tax: $" 
    << ((price_per_small_room * numbers_of_small_rooms) + (price_per_large_room * numbers_of_large_rooms)) * sales_tax 
    << std::endl;
  std::cout << "***************************************" << std::endl;
  std::cout 
    << "The total estimate: $" 
    << ((price_per_small_room * numbers_of_small_rooms) + (price_per_large_room * numbers_of_large_rooms)) +
      (((price_per_small_room * numbers_of_small_rooms) + (price_per_large_room * numbers_of_large_rooms)) * sales_tax)
    << std::endl;
  std::cout << "This estimate is valid for " << estimate_expiry << std::endl;

  return 0;
}
