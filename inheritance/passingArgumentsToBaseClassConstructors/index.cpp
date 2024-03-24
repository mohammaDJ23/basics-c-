#include <iostream>

class Base
{
public:
  int num;

  Base() : num{0} { std::cout << "Base constructor" << std::endl; }
  Base(int num) : num{num} { std::cout << "Base (int) constructor" << std::endl; }
  ~Base() { std::cout << "Base destructor" << std::endl; }
};

class Derived: public Base
{
public:
  int double_value;

  Derived() : Base{}, double_value{0} { std::cout << "Derived constructor" << std::endl; }
  Derived(int num) : Base{num}, double_value{num * 2} { std::cout << "Derived (int) constructor" << std::endl; }
  ~Derived() { std::cout << "Derived destructor" << std::endl; }
};

int main()
{
  // Base b;
  // Base b {10};
  // Derived d;
  Derived d {10};

  return 0;
}
