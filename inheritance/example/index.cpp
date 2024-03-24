#include <iostream>
#include <iomanip>
#include <vector>
#include "Account.h"
#include "Saving_account.h"
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

  return 0;
}
