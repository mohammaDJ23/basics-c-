/*

  constructors will call from the base class to derived class and
  destructors will call from derived to base class.
  for example:
    base constructor
    derived constructor
    derived destructor
    base destructor

  c++ will call the no args constructor of base class when you don't provide calling constructor of the base.

  you can use 'using Base::Base' in the derived class to call the base class constructors,
  but the derived constructors will not be used if you don't the derived constructors.

  a derived class does not inherit:
    base class constructors
    base class destructor
    base class overloaded assignment operators
    base class friend functions

  however, the derived class constructors, destructors, and overloaded
  assignment operators can invoke the base-class versions.

  c++11 allows explicit inheritance of base 'non-special' constructors
  with using Base::Base; anywhere in the derived class declaration.
  lots of rules involved, often better to define constructors yourself.

*/

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
  // using Base::Base;

public:
  int double_value;

  Derived() : double_value{0} { std::cout << "Derived constructor" << std::endl; }
  Derived(int num) : double_value{num * 2} { std::cout << "Derived (int) constructor" << std::endl; }
  ~Derived() { std::cout << "Derived destructor" << std::endl; }
};

int main()
{
  // Base b;
  // Base b {10};
  // Derived d;
  // Derived d {10};

  return 0;
}
