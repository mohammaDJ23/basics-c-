#include "Trust_account.h"

Trust_account::Trust_account(const std::string name, const double balance, const double int_rate)
  : Saving_account(name, balance, int_rate), num_withdrawls(0)
{}

bool Trust_account::deposit(double amount)
{
  if (amount >= this->bonus_threshold)
    amount += this->bonus_amount;
  return Saving_account::deposit(amount);
}

bool Trust_account::withdraw(double amount)
{
  if (this->num_withdrawls >= this->max_withdrawls || amount > this->balance * this->max_withdraw_percent)
    return false;

  this->num_withdrawls++;
  return Saving_account::withdraw(amount);
}

std::ostream &operator<<(std::ostream &os, const Trust_account &trust_account)
{
  os << "Trust_account: { name: " << trust_account.name 
    << ", balance: " << trust_account.balance 
    << ", int_rate: " << trust_account.int_rate
    << ", num_withdrawls: " << trust_account.num_withdrawls << " }";
  return os;
}
