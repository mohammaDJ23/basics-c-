/*

  sometimes you may write a function which can not be override.
  like this:
  
  class Base {
  public:
    void say_hello() const {}
  }

  class Derived: public Base {
  public:
    void say_hello() {}
  }

  in the derived say_hello function i forgot to use const.
  so this will not be override. here we use override keyword
  to check for the correctness.

*/

#include <iostream>
#include <vector>

class Account
{
public:
  virtual void withdraw(double amount) const
  {
    std::cout << "In Account withdraw" << std::endl;
  }

  virtual ~Account()
  {
    std::cout << "In Account destructor" << std::endl;
  }
};

class Checking_account: public Account
{
public:
  virtual void withdraw(double amount) const override
  {
    std::cout << "In Checking_account withdraw" << std::endl;
  }

  virtual ~Checking_account()
  {
    std::cout << "In Checking_account destructor" << std::endl;
  }
};

int main()
{
  Account *ptr1 = new Account();
  Account *ptr2 = new Checking_account();

  ptr1->withdraw(1000);
  ptr2->withdraw(1000);

  delete ptr1;
  delete ptr2;

  return 0;
}
