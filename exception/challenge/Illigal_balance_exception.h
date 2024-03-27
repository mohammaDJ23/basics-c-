#ifndef _ILLIGAL_BALANCE_EXCEPTION_H_
#define _ILLIGAL_BALANCE_EXCEPTION_H_

/*

    - noexcept means the function will not throw any exception.

    - the class destructor will never throw an exception so by default is noexcept.

*/

#include <iostream>

class Illigal_balance_exception: public std::exception
{
public:
    Illigal_balance_exception() noexcept = default;
    ~Illigal_balance_exception() = default;

    virtual const char *what() const noexcept override
    {
        return "Invalid balance.";
    }
};

#endif
