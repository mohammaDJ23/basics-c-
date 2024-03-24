#ifndef _SAVING_ACCOUNT_H_
#define _SAVING_ACCOUNT_H_

#include <iostream>
#include "Account.h"

class Saving_account: public Account
{
  friend std::ostream &operator<<(std::ostream &os, const Saving_account &saving_account);

protected:
  double int_rate;

public:
  Saving_account();
  Saving_account(const double balance, const double int_rate);

  void deposit(double amount);
};

#endif
