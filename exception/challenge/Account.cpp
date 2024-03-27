#include "Account.h"
#include "Illigal_balance_exception.h"
#include "Insufficent_funds_exception.h"

Account::Account(const std::string name, const double balance)
    :   name(name), balance(balance)
{
    if (balance < 0.0)
        throw Illigal_balance_exception();
}

bool Account::deposit(double amount)
{
    if (amount >= 0) {
        this->balance += amount;
        return true;
    }
    else
        return false;
}

bool Account::withdraw(double amount)
{
    if (this->balance - amount < 0)
        throw Insufficent_funds_exception();
    this->balance -= amount;
    return true;
}

double Account::get_balance() const
{
    return this->balance;
}
