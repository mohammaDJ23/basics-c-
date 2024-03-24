#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <iostream>

class Account
{
  friend std::ostream &operator<<(std::ostream &os, const Account &account);

protected:
  double balance;

public:
  Account();
  Account(const double balance);

  void deposit(const double amount);
  void withdraw(const double amount);
};

#endif
