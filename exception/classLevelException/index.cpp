/*

    - exceptions can also be thrown from within a class

    - method
        - these work the same way as they do for functions as we've seen

    - constructor
        - constructors may fail
        - constructors do not return any value
        - throw an exception in the constructor if you can not initialize an object

    - destructor
        - do not throw exceptions from your destructor

*/

#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_account.h"
#include "IlligalBalanceException.h"

int main()
{
    try
    {
        std::unique_ptr<Account> moes_account = std::make_unique<Checking_account>("Moe", -10.0);
        std::cout << *moes_account << std::endl;
    }
    catch(const IlligalBalanceException &ex)
    {
        std::cerr << "Could not initiate the account - negative balance" << std::endl;
    }

    std::cout << "Program completed successfully" << std::endl;
    
    return 0;
}
