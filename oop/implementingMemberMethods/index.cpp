#include <iostream>
#include "Account.h"

int main()
{
  Account test_account;

  test_account.set_name("mohammad nowresideh");
  test_account.set_balance(1000.0);

  if (test_account.deposit(200.0))
    std::cout << "Deposit ok." << std::endl;
  else
    std::cout << "Deposit not allowed." << std::endl;

  if (test_account.withdraw(500.0))
    std::cout << "Withdraw ok." << std::endl;
  else
    std::cout << "Not sufficient funds." << std::endl;

  if (test_account.withdraw(1500.0))
    std::cout << "Withdraw ok." << std::endl;
  else
    std::cout << "Not sufficient funds." << std::endl;

  return 0;
}
