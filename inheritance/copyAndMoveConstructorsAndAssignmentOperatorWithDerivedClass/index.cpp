#include <iostream>

class Base
{
public:
  int num;

  Base() : num{0} 
  { 
    std::cout << "Base constructor" << std::endl; 
  }
  
  Base(int num) 
    : num{num} 
  { 
    std::cout << "Base (int) constructor" << std::endl; 
  }

  Base(const Base &source)
    : num{source.num} 
  {
    std::cout << "Base copy constructor" << std::endl;
  }

  Base(Base &&source)
    : num{source.num}
  {
    std::cout << "Base move constructor" << std::endl;
    source.num = 0;
  }

  Base &operator=(const Base &rhs)
  {
    std::cout << "Base copy assignment operator" << std::endl;

    if (this == &rhs)
      return *this;
    
    this->num = rhs.num;
    return *this;
  }

  Base &operator=(Base &&rhs)
  {
    std::cout << "Base move assignment operator" << std::endl;

    if (this == &rhs)
      return *this;
    
    this->num = rhs.num;
    rhs.num = 0;
    return *this;
  }

  ~Base() 
  { 
    std::cout << "Base destructor" << std::endl; 
  }
};

class Derived: public Base
{
public:
  int double_value;

  Derived() 
    : Base{}, double_value{0} 
  { 
    std::cout << "Derived constructor" << std::endl; 
  }
  
  Derived(int num) 
    : Base{num}, double_value{num * 2} 
  { 
    std::cout << "Derived (int) constructor" << std::endl; 
  }

  Derived(const Derived &source)
    : Base{source}, double_value{source.double_value}
  {
    std::cout << "Derived copy constructor" << std::endl;
  }

  Derived(Derived &&source)
    : Base{source}, double_value{source.double_value}
  {
    std::cout << "Derived copy constructor" << std::endl;
    source.double_value = 0;
  }

  Derived &operator=(const Derived &rhs)
  {
    std::cout << "Derived copy assignment operator" << std::endl;

    if (this == &rhs)
      return *this;
    
    Base::operator=(rhs);
    this->double_value = rhs.double_value;
    return *this;
  }

  Derived &operator=(Derived &&rhs)
  {
    std::cout << "Derived move assignment operator" << std::endl;

    if (this == &rhs)
      return *this;
    
    Base::operator=(std::move(rhs));
    this->double_value = rhs.double_value;
    rhs.double_value = 0;
    return *this;
  }

  ~Derived() 
  { 
    std::cout << "Derived destructor" << std::endl; 
  }
};

int main()
{
  Derived d {10};
  Derived d1;
  Derived d2 {d};

  d1 = d2;
  d1 = Derived{100};

  return 0;
}
