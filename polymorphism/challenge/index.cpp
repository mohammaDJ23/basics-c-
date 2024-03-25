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
  Account *ptr1 = new Saving_account();
  Account *ptr2 = new Saving_account("Superman");
  Account *ptr3 = new Saving_account("Batman", 2000);
  Account *ptr4 = new Saving_account("Wonderwoman", 5000, 5.0);

  std::vector<Account*> saving_accounts {ptr1, ptr2, ptr3, ptr4};

  display(saving_accounts);
  deposit(saving_accounts, 1000);
  withdraw(saving_accounts, 2000);

  delete ptr1;
  delete ptr2;
  delete ptr3;
  delete ptr4;

  Account *ptr5 = new Checking_account();
  Account *ptr6 = new Checking_account("Jack");
  Account *ptr7 = new Checking_account("Paul", 2000);
  Account *ptr8 = new Checking_account("Poo", 5000);

  std::vector<Account*> checking_accounts {ptr5, ptr6, ptr7, ptr8};

  display(checking_accounts);
  deposit(checking_accounts, 1000);
  withdraw(checking_accounts, 2000);

  delete ptr5;
  delete ptr6;
  delete ptr7;
  delete ptr8;

  Account *ptr9 = new Trust_account("Mes");
  Account *ptr10 = new Trust_account("Jack");
  Account *ptr11 = new Trust_account("Paul", 2000);
  Account *ptr12 = new Trust_account("Poo", 5000, 2.0);

  std::vector<Account*> trust_accounts {ptr9, ptr10, ptr11, ptr12};

  display(trust_accounts);
  deposit(trust_accounts, 1000);
  withdraw(trust_accounts, 1000);
  withdraw(trust_accounts, 1000);
  withdraw(trust_accounts, 500);
  withdraw(trust_accounts, 50);

  delete ptr9;
  delete ptr10;
  delete ptr11;
  delete ptr12;

  return 0;
}
