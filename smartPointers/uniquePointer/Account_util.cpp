#include "Account_util.h"

void display(const std::vector<Account*> &accounts)
{
  for (const auto &ptr: accounts)
    std::cout << *ptr << std::endl;
}

void deposit(std::vector<Account*> &accounts, double amount)
{
  for (const auto &ptr: accounts)
    if (ptr->deposit(amount))
      std::cout << "Deposited " << amount << " to " << *ptr << std::endl;
    else
      std::cout << "Failed deposit of " << amount << " to " << *ptr << std::endl;
}

void withdraw(std::vector<Account*> &accounts, double amount)
{
  for (const auto &ptr: accounts)
    if (ptr->withdraw(amount))
      std::cout << "Withdraw " << amount << " from " << *ptr << std::endl;
    else
      std::cout << "Failed withdraw of " << amount << " from " << *ptr << std::endl;
}
