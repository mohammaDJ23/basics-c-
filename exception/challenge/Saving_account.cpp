#include <iostream>
#include <iomanip>
#include "Saving_account.h"

Saving_account::Saving_account(const std::string name, const double balance, const double int_rate)
  : Account(name , balance), int_rate(int_rate)
{}

bool Saving_account::deposit(double amount) 
{
  amount += amount * (int_rate / 100);
  return Account::deposit(amount);
}

bool Saving_account::withdraw(double amount) 
{
  return Account::withdraw(amount);
}

void Saving_account::print(std::ostream &os) const 
{
  std::cout << std::fixed << std::setprecision(2);
  os << "Saving_account: { name: " << this->name 
    << ", balance: " << this->balance 
    << ", int_rate: " << this->int_rate << " }";
}
