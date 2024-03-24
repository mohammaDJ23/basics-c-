#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_

#include <iostream>
#include <vector>
#include "Account.h"
#include "Saving_account.h"

void display(const std::vector<Account> &accounts);
void deposit(std::vector<Account> &accounts, double amount);
void withdraw(std::vector<Account> &accounts, double amount);

void display(const std::vector<Saving_account> &saving_accounts);
void deposit(std::vector<Saving_account> &saving_accounts, double amount);
void withdraw(std::vector<Saving_account> &saving_accounts, double amount);

#endif
