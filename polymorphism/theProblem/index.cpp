/*

  - fundamental to oop

  - polymorphism
    - compile-time / early binding / static binding
      the example below used this one by default based on the type of the variable or ptr.
      like this => Base *ptr1 = new Derived();
      it used Base type for binding at compile time.

    - run-time / late binding / dynamic binding

  - runtime polymorphism
    - being able to assign different meanings to the same function at run-time

  - allows us to program more abstractly
    - think general vs specific
    - let c++ figure out which function to call at run-time
  
  - not the default in c++, run-time polymorphism is achieved via
    - inheritance
    - Base class pointers or references
    - virtual functions

*/

#include <iostream>
#include <memory>

class Base
{
public:
  void say_hello() const
  {
    std::cout << "Hello, i'm a base class." << std::endl;
  }
};

class Derived: public Base
{
public:
  void say_hello() const
  {
    std::cout << "Hello, i'm a derived class." << std::endl;
  }
};

void greeting(const Base &obj)
{
  std::cout << "Greeting: ";
  obj.say_hello();
}

int main()
{
  Base b;
  b.say_hello();

  Derived d;
  d.say_hello();

  greeting(b);
  greeting(d); // problem: this will call say_hello of Base

  Base *ptr1 = new Derived();
  ptr1->say_hello(); // problem: this will call say_hello of Base
  delete ptr1;

  std::unique_ptr<Base> ptr2 = std::make_unique<Derived>();
  ptr2->say_hello(); // problem: this will call say_hello of Base

  return 0;
}
