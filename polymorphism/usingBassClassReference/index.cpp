#include <iostream>
#include <vector>

class Account
{
public:
  virtual void withdraw(const double amount) const
  {
    std::cout << "In Account withdraw" << std::endl;
  }
};

class Checking_account: public Account
{
public:
  virtual void withdraw(const double amount) const override
  {
    std::cout << "In Checking_account withdraw" << std::endl;
  }
};

class Saving_account: public Account
{
public:
  virtual void withdraw(const double amount) const override
  {
    std::cout << "In Saving_account withdraw" << std::endl;
  }
};

class Trust_account: public Account
{
public:
  virtual void withdraw(const double amount) const override
  {
    std::cout << "In Trust_account withdraw" << std::endl;
  }
};

void do_withdraw(const Account &account, const double amount)
{
  account.withdraw(amount);
}

int main()
{
  Account a;
  Account &a1 {a};
  a1.withdraw(1000);

  Trust_account t;
  Account &t1 {t};
  t1.withdraw(1000);

  do_withdraw(Account {}, 1000);
  do_withdraw(Checking_account {}, 1000);
  do_withdraw(Saving_account {}, 1000);
  do_withdraw(Trust_account {}, 1000);

  return 0;
}
