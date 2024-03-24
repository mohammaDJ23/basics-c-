#include "Account.h"

Account::Account(const std::string name, const double balance)
  : name(name), balance(balance)
{}

bool Account::deposit(const double amount)
{
  if (amount >= 0) {
    this->balance += amount;
    return true;
  }
  else
    return false;
}

bool Account::withdraw(const double amount)
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

std::ostream &operator<<(std::ostream &os, const Account &account)
{
  os << "Account: { name: " << account.name << ", balance: " << account.balance << " }";
  return os;
}