/*

  The final specifier

  - c++11 provides the final specifier:
    - when used at the class level
      - prevents a claas from being derived from

    - when used at the method level
      - prevents virtual method from being overridden in derived class

*/

#include <iostream>
#include <vector>

class Account final
{
public:
  virtual void withdraw(double amount) const final
  {
    std::cout << "In Account withdraw" << std::endl;
  }

  virtual ~Account()
  {
    std::cout << "In Account destructor" << std::endl;
  }
};

// Error becuase the Account class can not be drived from
class Checking_account: public Account
{
public:
  // error the function can not be override
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
