#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <iostream>

class Account
{
  friend std::ostream &operator<<(std::ostream &os, const Account &account);

private:
  static constexpr const char *def_name = "Unnamed Account";
  static constexpr double def_balance = 0.0;

protected:
  std::string name;
  double balance;

public:
  Account(const std::string name = def_name, const double balance = def_balance);

  bool deposit(const double amount);
  bool withdraw(const double amount);
  double get_balance() const;
};

#endif
