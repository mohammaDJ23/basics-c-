#include <iostream>
#include "Account.h"
#include "Saving_account.h"

int main()
{
  std::cout << "========Account========" << std::endl;

  Account a1 {1000.0};
  std::cout << a1 << std::endl;

  a1.deposit(500.0);
  std::cout << a1 << std::endl;

  a1.withdraw(1000.0);
  std::cout << a1 << std::endl;

  a1.withdraw(5000.0);
  std::cout << a1 << std::endl;

  std::cout << "========Saving account========" << std::endl;

  Saving_account a2 {1000.0, 5.0};
  std::cout << a2 << std::endl;

  a2.deposit(1000.0);
  std::cout << a2 << std::endl;

  a2.withdraw(2000.0);
  std::cout << a2 << std::endl;

  a2.withdraw(1000.0);
  std::cout << a2 << std::endl;

  return 0;
}
