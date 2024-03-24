#include "Checking_account.h"

Checking_account::Checking_account(const std::string name, const double balance)
  : Account(name, balance)
{}

bool Checking_account::withdraw(double amount)
{
  amount += this->fee_withdraw;
  return Account::withdraw(amount);
}

std::ostream &operator<<(std::ostream &os, const Checking_account &checking_account)
{
  os << "Checking_account: { name: " << checking_account.name << ", balance: " << checking_account.balance << " }";
  return os;
}
