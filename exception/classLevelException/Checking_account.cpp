#include <iostream>
#include <iomanip>
#include "Checking_account.h" 

Checking_account::Checking_account(const std::string name, const double balance)
  : Account(name, balance)
{}

bool Checking_account::deposit(double amount)
{
  return Account::deposit(amount);
}

bool Checking_account::withdraw(double amount)
{
  amount += this->fee_withdraw;
  return Account::withdraw(amount);
}

void Checking_account::print(std::ostream &os) const
{
  std::cout << std::fixed << std::setprecision(2);
  os << "Checking_account: { name: " << this->name << ", balance: " << this->balance << " }";
}
