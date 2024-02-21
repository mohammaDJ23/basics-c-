/*

  Shipping cost calculator

  Ask the user for package dimension in inches
  length, width, height should be inches

  All dimension must be 10 inches or less or we can not ship it

  Base cost $2.50

  If the package volume is greater than 100 cube inches there is 10% surcharge
  If the package volume is greater than 500 cube inches there is 25% surcharge

*/

#include <iostream>
#include <iomanip>

int main()
{
  const int max_dimension {10};
  const double base_cost {2.50};
  const int tier1_threshold {100};
  const int tier2_threshold {500};
  const double tier1_surchase {0.10};
  const double tier2_surchase {0.25};

  int width {0};
  int height {0};
  int length {0};

  std::cout << "Enter the width, height and length of your package in inches: ";
  std::cin >> width >> height >> length;

  if (width <= 0 || height <= 0 || length <= 0) 
    std::cout << "The dimension is invalid." << std::endl;
  else if (width > max_dimension || height > max_dimension || length > max_dimension) 
    std::cout << "We could not ship this package, becuase it has more than " 
      << max_dimension << " inches dimension." << std::endl;
  else {
    int volume {0};
    double cost {base_cost};

    volume = width * height * length;

    if (volume > tier2_threshold)
      cost += base_cost * tier2_surchase;
    else if (volume > tier1_threshold)
      cost += base_cost * tier1_surchase;

    // prints two decimal
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "The package volume is " << volume << " and the cost is $" << cost << std::endl;
  }

  return 0;
}
