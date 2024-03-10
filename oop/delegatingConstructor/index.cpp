/*

  as you see here we are using the list initialization.
  but there is an issue that is the duplication of the codes.
  see the example below to see what is going on.

  we use the maximum arguments constructor as a delegation.

  notice the below constructor with initialization and the body works for all the place which is delegated.

    Account::Account(std::string n, std::string t, double b)
      : name{n}, type{t}, balance{b} 
    {
      std::cout << "Name, type and balance arguments are called." << std::endl;
    }

*/

#include <iostream>
#include <string>

class Account
{
private:
  std::string name;
  std::string type;
  double balance;

public:
  Account(void);
  Account(std::string n);
  Account(std::string n, std::string t, double b);
};

Account::Account()
  : Account{"Unknown", "USD", 0.0} 
{
  std::cout << "No argument is called." << std::endl;
}

Account::Account(std::string n)
  : Account{n, "USD", 0.0} 
{
  std::cout << "Name argument is called." << std::endl;
}

Account::Account(std::string n, std::string t, double b)
  : name{n}, type{t}, balance{b} 
{
  std::cout << "Name, type and balance arguments are called." << std::endl;
}

int main()
{
  Account person;

  return 0;
}
