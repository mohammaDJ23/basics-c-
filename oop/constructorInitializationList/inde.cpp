/*

  at the previous example we initialize the constructor in the body:
  Account::Account()
  {
    name = "Frank";
    health = 100;
    xp = 3;
  }

  this is not actualy an initialization. this is assignment.
  the default values are not apply until in the body of the constructor.
  so this is not the best practice.

  we use list initialization.

*/

#include <iostream>
#include <string>

class Account
{
private:
  std::string name;
  double balance;

public:
  Account(void);
  Account(std::string n);
  Account(std::string n, double b);
};

Account::Account()
  : name{"Unknown"}, balance{0.0} 
{}

Account::Account(std::string n)
  : name{n}, balance{0.0}
{}

Account::Account(std::string n, double b)
  : name{n}, balance{b} 
{}

int main()
{
  Account person;

  return 0;
}
