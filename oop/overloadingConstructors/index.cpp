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
{
  name = "Unknown";
  balance = 0.0;
}

Account::Account(std::string n)
{
  name = n;
  balance = 0.0;
}

Account::Account(std::string n, double b)
{
  name = n;
  balance = b;
}

int main()
{
  Account person1;

  Account person2 {"Jack"};

  Account person3 {"Mike", 5000.0};

  Account *person4_ptr = new Account("Moe", 4000.0);
  delete person4_ptr;

  return 0;
}
