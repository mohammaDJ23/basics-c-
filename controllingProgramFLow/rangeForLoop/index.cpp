#include <iostream>
#include <vector>
#include <iomanip>

int main()
{
  std::vector<double> temperatures {10.2, 44.8, 34.9, 56.8};
  double temp_avg {0.0};
  double total {0.0};

  for (auto temperature : temperatures)
    total += temperature;

  temp_avg = total / temperatures.size();

  std::cout << std::fixed << std::setprecision(1);
  std::cout << "Avrage temperature is " << temp_avg << std::endl;

  return 0;
}
