#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <iostream>
#include "I_Printable.h"

class Account : public I_Printable
{
private:
  static constexpr const char *def_name = "Unnamed Account";
  static constexpr double def_balance = 0.0;

protected:
  std::string name;
  double balance;

public:
  Account(const std::string name = def_name, const double balance = def_balance);

  virtual ~Account() = default;

  virtual bool deposit(double amount) = 0;
  virtual bool withdraw(double amount) = 0;

  double get_balance() const;
};

#endif
