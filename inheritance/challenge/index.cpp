#include <iostream>
#include <iomanip>
#include <vector>
#include "Account.h"
#include "Saving_account.h"
#include "Checking_account.h"
#include "Trust_account.h"
#include "Account_util.h"

int main()
{
  std::cout << std::fixed << std::setprecision(2);

  std::vector<Account> accounts;

  accounts.push_back(Account {});
  accounts.push_back(Account {"Larry"});
  accounts.push_back(Account {"Moe", 2000});
  accounts.push_back(Account {"Curly", 5000});

  display(accounts);
  deposit(accounts, 1000);
  withdraw(accounts, 2000);

  std::vector<Saving_account> saving_accounts;

  saving_accounts.push_back(Saving_account {});
  saving_accounts.push_back(Saving_account {"Superman"});
  saving_accounts.push_back(Saving_account {"Batman", 2000});
  saving_accounts.push_back(Saving_account {"Wonderwoman", 5000, 5.0});

  display(saving_accounts);
  deposit(saving_accounts, 1000);
  withdraw(saving_accounts, 2000);

  std::vector<Checking_account> checking_accounts;

  checking_accounts.push_back(Checking_account {});
  checking_accounts.push_back(Checking_account {"Jack"});
  checking_accounts.push_back(Checking_account {"Paul", 2000});
  checking_accounts.push_back(Checking_account {"Poo", 5000});

  display(checking_accounts);
  deposit(checking_accounts, 1000);
  withdraw(checking_accounts, 2000);

  std::vector<Trust_account> trust_accounts;

  trust_accounts.push_back(Trust_account {"Mes"});
  trust_accounts.push_back(Trust_account {"Jack"});
  trust_accounts.push_back(Trust_account {"Paul", 2000});
  trust_accounts.push_back(Trust_account {"Poo", 5000, 2.0});

  display(trust_accounts);
  deposit(trust_accounts, 1000);
  withdraw(trust_accounts, 1000);
  withdraw(trust_accounts, 1000);
  withdraw(trust_accounts, 500);
  withdraw(trust_accounts, 50);

  return 0;
}
