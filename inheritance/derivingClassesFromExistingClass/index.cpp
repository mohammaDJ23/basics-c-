#include <iostream>
#include "Account.h"
#include "Saving_account.h"

int main()
{
  std::cout << "Account" << std::endl << "=================================" << std::endl;

  Account acc {};
  acc.deposit(1000.0);
  acc.withdraw(200.0);
  
  Account *acc_ptr {nullptr};
  acc_ptr = new Account();
  acc_ptr->deposit(2000.0);
  acc_ptr->withdraw(400.0);
  delete acc_ptr;

  std::cout << std::endl << "Saving_account" << std::endl << "=================================" << std::endl;

  Saving_account saving_acc {};
  saving_acc.deposit(1000.0);
  saving_acc.withdraw(200.0);
  
  Saving_account *saving_acc_ptr {nullptr};
  saving_acc_ptr = new Saving_account();
  saving_acc_ptr->deposit(2000.0);
  saving_acc_ptr->withdraw(400.0);
  delete saving_acc_ptr;

  return 0;
}
