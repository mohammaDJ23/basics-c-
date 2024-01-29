#include <iostream>

int main()
{
  const double eur_to_usd {1.5};

  std::cout << "Enter the value in EUR: ";
  
  double eur {0};
  std::cin >> eur;

  std::cout << eur << " EUR to USD will be: " << eur * eur_to_usd << "." << std::endl;

  return 0;
}
