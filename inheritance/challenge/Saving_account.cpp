#include "Saving_account.h"

Saving_account::Saving_account(const std::string name, const double balance, const double int_rate)
  : Account(name , balance), int_rate(int_rate)
{}

bool Saving_account::deposit(double amount)
{
  amount += amount * (int_rate / 100);
  return Account::deposit(amount);
}

std::ostream &operator<<(std::ostream &os, const Saving_account &saving_account)
{
  os << "Saving_account: { name: " << saving_account.name 
    << ", balance: " << saving_account.balance << ", int_rate: " 
    << saving_account.int_rate << " }";
  return os;
}
