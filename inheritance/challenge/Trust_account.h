#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_

#include <iostream>
#include <string>
#include "Saving_account.h"

class Trust_account: public Saving_account
{
  friend std::ostream &operator<<(std::ostream &os, const Trust_account &trust_account);

private:
  static constexpr const char *def_name = "Unnamed trust account";
  static constexpr double def_balance = 0.0;
  static constexpr double def_int_rate = 0.0;
  static constexpr double bonus_amount = 50.0;
  static constexpr double bonus_threshold = 5000.0;
  static constexpr int max_withdrawls = 3;
  static constexpr double max_withdraw_percent = 0.2;

protected:
  int num_withdrawls;

public:
  Trust_account(const std::string name = def_name, 
    const double balance = def_balance, 
    const double int_rate = def_int_rate);

  bool deposit(double amount);
  bool withdraw(double amount);
};

#endif
