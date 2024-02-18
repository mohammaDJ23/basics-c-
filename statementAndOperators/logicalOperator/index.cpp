#include <iostream>

int main()
{
  int num {};
  const int lower {10};
  const int upper {20};

  std::cout << std::boolalpha;

  std::cout << "Enter an integer - the bound is " << lower << " - " << upper << ": ";
  std::cin >> num;

  bool within_bounds {false};
  within_bounds = num > lower && num < upper;
  std::cout << num << " is between " << lower << " - " << upper << ": " << within_bounds << std::endl << std::endl;

  std::cout << "Enter an integer - the bound is " << lower << " - " << upper << ": ";
  std::cin >> num;

  bool outside_bounds {false};
  outside_bounds = num < lower || num > upper;
  std::cout << num << " is outside " << lower << " - " << upper << ": " << outside_bounds << std::endl << std::endl;

  std::cout << "Enter an integer - the bound is " << lower << " - " << upper << ": ";
  std::cin >> num;

  bool on_bounds {false};
  on_bounds = num == lower || num == upper;
  std::cout << num << " is on one the bounds which are " << lower << " - " << upper << ": " << on_bounds << std::endl << std::endl;

  const int wind_speed_for_coat {25};
  const double temperature_for_coat {45.0};
  double temperature {0.0};
  int wind_speed {0};
  bool wear_coat {false};

  std::cout << "Enter the current tempreture in F: ";
  std::cin >> temperature;
  std::cout << "Enter the current wind speed in mph: ";
  std::cin >> wind_speed;

  wear_coat = wind_speed > wind_speed_for_coat && temperature < temperature_for_coat;
  std::cout << "Do you need a coat using AND: " << wear_coat << std::endl;

  wear_coat = wind_speed > wind_speed_for_coat || temperature < temperature_for_coat; 
  std::cout << "Do you need a coat using OR: " << wear_coat << std::endl; 
  
  return 0;
}
