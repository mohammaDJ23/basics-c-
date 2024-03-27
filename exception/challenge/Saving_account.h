#ifndef _SAVING_ACCOUNT_H_
#define _SAVING_ACCOUNT_H_

#include <iostream>
#include <string>
#include "Account.h"

class Saving_account: public Account
{
private:
  static constexpr const char *def_name = "Unnamed savings account";
  static constexpr double def_balance = 0.0;
  static constexpr double def_int_rate = 0.0;

protected:
  double int_rate;

public:
  Saving_account(const std::string name = def_name, 
    const double balance = def_balance, 
    const double int_rate = def_int_rate);
  
  virtual ~Saving_account() = default;

  virtual bool deposit(double amount) override;
  virtual bool withdraw(double amount) override;
  virtual void print(std::ostream &os) const override;
};

#endif
