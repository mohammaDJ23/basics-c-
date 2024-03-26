#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_

#include "Account.h"

class Checking_account final: public Account
{
private:
  static constexpr const char *def_name = "Unnamed checking account";
  static constexpr double def_balance = 0.0;
  static constexpr double fee_withdraw = 1.50;

public:
  Checking_account(const std::string name = def_name, const double balance = def_balance);

  virtual ~Checking_account() = default;

  virtual bool deposit(double amount) override;
  virtual bool withdraw(double amount) override;
  virtual void print(std::ostream &os) const override;
};

#endif
