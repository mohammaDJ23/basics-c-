#include <iostream>
#include <iomanip>
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

void Trust_account::print(std::ostream &os) const 
{
  std::cout << std::fixed << std::setprecision(2);
  os << "Trust_account: { name: " << this->name 
    << ", balance: " << this->balance 
    << ", int_rate: " << this->int_rate
    << ", num_withdrawls: " << this->num_withdrawls << " }";
}
