#include <iostream>

int main()
{
  for (;;)
    std::cout << "This will print forever." << std::endl;

  while (true)
    std::cout << "This will print forever." << std::endl;
  
  do {
    std::cout << "This will print forever." << std::endl;
  } while (true);

  return 0;
}
