#include "Account.h"

Account::Account()
  : Account(0.0)
{}

Account::Account(const double balance)
  : balance(balance)
{}

void Account::deposit(const double amount)
{
  this->balance += amount;
}

void Account::withdraw(const double amount)
{
  if (this->balance - amount >= 0)
    this->balance -= amount;
  else
    std::cout << "Insuffcient funds" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Account &account)
{
  os << "Account balance: " << account.balance;
  return os;
}
