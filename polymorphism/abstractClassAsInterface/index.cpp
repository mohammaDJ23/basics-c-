/*

  imagin this example for printing an object:

  class Account {
    firend std::ostream &operator<<(std::ostream &os, const Account &obj);
  }
  std::ostream &operator<<(std::ostream &os, const Account &obj) {
    os << "Printing account";
    return os;
  }

  class Checkout: public Account {
    firend std::ostream &operator<<(std::ostream &os, const Checkout &obj);
  }
  std::ostream &operator<<(std::ostream &os, const Checkout &obj) {
    os << "Printing checkout";
    return os;
  }

  Account *ptr1 = new Account();
  std::cout << *ptr1 << std::endl; // Printing account
  Account *ptr2 = new Checkout();
  std::cout << *ptr2 << std::endl; // Printing account




  another example:

  void print(const Account &obj) {
    std::cout << obj << std::endl;
  }

  Account *ptr1 = new Account();
  print(*ptr1); // Printing account
  Account *ptr2 = new Checkout();
  print(*ptr2); // Printing account




  there is a problem since the << operator is not a virtual function.
  so the compiler will use the Account version.
  check the below example to prevent this behavior.
  at this example you have to use an abstract class as an interface.

*/

#include <iostream>

// I_Printable mean interface_printable as an interface
// I_Printable is an abstract class
class I_Printable
{
  friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);

public:
  virtual void print(std::ostream &os) const = 0;
  virtual ~I_Printable() {}
};

std::ostream &operator<<(std::ostream &os, const I_Printable &obj)
{
  obj.print(os);
  return os;
}

class Account: public I_Printable
{
public:
  virtual void print(std::ostream &os) const override 
  {
    std::cout << "Printing account";
  }
};

class Checkout final: public Account 
{
  virtual void print(std::ostream &os) const override 
  {
    std::cout << "Printing checkout";
  }
};

void print(const I_Printable &obj)
{
  std::cout << obj << std::endl;
}

int main()
{
  Account *ptr1 = new Account();
  std::cout << *ptr1 << std::endl;

  Account *ptr2 = new Checkout();
  std::cout << *ptr2 << std::endl;

  print(*ptr1);
  print(*ptr2);

  return 0;
}
