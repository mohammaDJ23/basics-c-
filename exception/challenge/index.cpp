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
#include "Illigal_balance_exception.h"
#include "Insufficent_funds_exception.h"

int main()
{
    try
    {
        std::unique_ptr<Account> moes_account = std::make_unique<Checking_account>("Moe", 1000.0);
        std::cout << *moes_account << std::endl;
        moes_account->withdraw(5000);
        std::cout << *moes_account << std::endl;
    }
    catch(const Illigal_balance_exception &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    catch(const Insufficent_funds_exception &ex)
    {
        std::cerr << ex.what() << std::endl;
    }

    std::cout << "Program completed successfully" << std::endl;
    
    return 0;
}
