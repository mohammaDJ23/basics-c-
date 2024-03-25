#include "Account.h"

Account::Account(const std::string name, const double balance)
  : name(name), balance(balance)
{}

bool Account::deposit(double amount)
{
  if (amount >= 0) {
    this->balance += amount;
    return true;
  }
  else
    return false;
}

bool Account::withdraw(double amount)
{
  if (this->balance - amount >= 0) {
    this->balance -= amount;
    return true;
  }
  else
    return false;
}

double Account::get_balance() const
{
  return this->balance;
}
