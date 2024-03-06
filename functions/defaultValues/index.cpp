/*

  it's better to define the default values inside the prototype of the function.

*/

#include <iostream>
#include <iomanip>

double calc_cost(double base_cost = 100.0, double tax_rate = 0.06, double shipping = 3.50);

double calc_cost(double base_cost, double tax_rate, double shipping)
{
  return base_cost += (base_cost * tax_rate) + shipping;
}

int main()
{
  double cost {0.0};

  std::cout << std::fixed << std::setprecision(2);

  cost = calc_cost(120.0, 0.08, 3.67);
  std::cout << cost << std::endl;

  cost = calc_cost(120.0, 0.08);
  std::cout << cost << std::endl;

  cost = calc_cost(120.0);
  std::cout << cost << std::endl;

  cost = calc_cost();
  std::cout << cost << std::endl;

  return 0;
}
