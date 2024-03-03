#include <iostream>
#include <vector>

int main()
{
  for (int i {1}; i <= 10; i++) 
    for (int j {1}; j <= 10; j++) 
      std::cout << i << " * " << j << " = " << i * j << std::endl;

  std::cout << std::endl;

  for (int i {1}, j {6}; i <= 5; i++, j++)
    std::cout << i << " + " << j << " = " << i + j << std::endl;

  std::cout << std::endl;
  
  std::vector<int> vec {10, 20, 30, 40, 50};

  for (unsigned int i {}; i < vec.size(); i++)
    std::cout << vec.at(i) << std::endl;

  std::cout << std::endl;

  for (int i {1}; i <= 100; i++) {
    std::cout << i;

    if (i % 10 == 0)
      std::cout << std::endl;
    else
      std::cout << " ";
  }

  return 0;
}
