#include <iostream>
#include "Saving_account.h"

Saving_account::Saving_account()
  : int_rate{0.0}
{}

Saving_account::~Saving_account()
{}

void Saving_account::deposit(double amount)
{
  std::cout << "Saving_account deposit called with " << amount << std::endl;
}

void Saving_account::withdraw(double amount)
{
  std::cout << "Saving_account withdraw called with " << amount << std::endl;
}
