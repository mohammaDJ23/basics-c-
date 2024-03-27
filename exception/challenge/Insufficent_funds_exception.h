#ifndef _INSUFFIENT_FUNDS_EXCEPTION_H_
#define _INSUFFIENT_FUNDS_EXCEPTION_H_

/*

    - noexcept means the function will not throw any exception.

    - the class destructor will never throw an exception so by default is noexcept.

*/

#include <iostream>

class Insufficent_funds_exception: public std::exception
{
public:
    Insufficent_funds_exception() noexcept = default;
    ~Insufficent_funds_exception() = default;

    virtual const char *what() const noexcept override
    {
        return "Isufficent funds.";
    }
};

#endif
