#ifndef _SAVING_ACCOUNT_H_
#define _SAVING_ACCOUNT_H_

#include "Account.h"

class Saving_account: public Account
{
public:
  double int_rate;

  Saving_account();
  ~Saving_account();

  void deposit(double amount);
  void withdraw(double amount);
};

#endif
