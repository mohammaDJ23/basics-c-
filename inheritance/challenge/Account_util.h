#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_

#include <iostream>
#include <vector>
#include "Account.h"
#include "Saving_account.h"
#include "Checking_account.h"
#include "Trust_account.h"

void display(const std::vector<Account> &accounts);
void deposit(std::vector<Account> &accounts, double amount);
void withdraw(std::vector<Account> &accounts, double amount);

void display(const std::vector<Saving_account> &saving_accounts);
void deposit(std::vector<Saving_account> &saving_accounts, double amount);
void withdraw(std::vector<Saving_account> &saving_accounts, double amount);

void display(const std::vector<Checking_account> &checking_accounts);
void deposit(std::vector<Checking_account> &checking_accounts, double amount);
void withdraw(std::vector<Checking_account> &checking_accounts, double amount);

void display(const std::vector<Trust_account> &trust_accounts);
void deposit(std::vector<Trust_account> &trust_accounts, double amount);
void withdraw(std::vector<Trust_account> &trust_accounts, double amount);

#endif
