/*

  these preprocessor is for creating an account class once.
  it means if you include this file multi times inside the other files,
  this will manage to create just once.

  _ACCOUNT_H_ is just a name.

  here is the abstraction the class.
  the class methods are defined as prototype of the class in the Account.cpp file.

  at some compilters we could use => #pragma once

  #pragma once

  class Account
  {
    
  }

*/

#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <string>

class Account
{
private:
  std::string name;
  double balance;

public:
  void set_balance(double val);
  double get_balance(void);
  void set_name(std::string val);
  std::string get_name(void);
  bool deposit(double amount);
  bool withdraw(double amount);
};

#endif
