#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <iostream>
#include <string>

class Account
{
public:
  double balance;
  std::string name;

  Account();
  ~Account();

  void deposit(double amount);
  void withdraw(double amount);
};

#endif
