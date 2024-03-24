#include "Saving_account.h"

Saving_account::Saving_account()
  : Saving_account(0.0, 0.0)
{}

Saving_account::Saving_account(const double balance, const double int_rate)
  : Account(balance), int_rate(int_rate)
{}

void Saving_account::deposit(double amount)
{
  amount = amount + (amount * int_rate / 100);
  Account::deposit(amount);
}

std::ostream &operator<<(std::ostream &os, const Saving_account &saving_account)
{
  os << "Saving account balance: " << saving_account.balance << " interest rate: " << saving_account.int_rate;
  return os;
}