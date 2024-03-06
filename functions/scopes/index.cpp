#include <iostream>

int main()
{
  int num {10};

  std::cout << "num is: " << num << std::endl;

  {
    int num {20};

    std::cout << "num inside the scope is: " << num << std::endl;
  }

  return 0;
}
