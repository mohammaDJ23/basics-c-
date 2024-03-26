/*

  unique_ptr

  - simple smart pointer - very effcient

  - unique_ptr<T>
    - points to an object of type T on the heap
    - it is unique. there can be only be on unique_ptr<T> pointing to the object on the heap
    - owns what is points to
    - cannot be assigned or copied
    - can be moved
    - pointer arithmetic not supported (++, --, etc)
    - when the pointer is destroyed, what it points to is automatically destroyed
    - after an scope the pointer and what it points to will be destroy

  - initialization
    - std::unique_ptr<int> ptr {new int {100}};
    - std::unique_ptr<int> ptr = std::make_unique<int>(0);

    - the second initilization is better but sometimes we have to use the first one.

  - example:
    {
      std::unique_ptr<int> p1 = std::make_unique<int>(0);
      *p1 = 100;
      std::cout << *p1 << std::endl; // 100
    } // automatically deleted

  - example:
    {
      std::unique_ptr<int> p1 = std::make_unique<int>(0);
      std::cout << p1.get() << std::endl; // 0*545623423
      p1.reset(); // p1 is now nullptr
      if (p1)
        std::cout << *p1 << std::endl; // won't execute
    } // automatically deleted

  - example:
    {
      std::unique_ptr<Account> p1 = std::make_unique<Account>("Larry");
      std::cout << *p1 << std::endl; // display account
      p1->deposit(1000);
      p1->withdraw(300);
    } // automatically deleted

  - example:
    {
      std::vector<std::unique_ptr<int>> vec;
      std::unique_ptr<int> p1 = std::make_unique<int>(10);
      vec.push_back(p1); // Error - copy not allowd
      vec.push_back(std::move(p1));
    } // automatically deleted

  - example:
    {
      std::unique_ptr<int> p1 = std::make_unique<int>(10);
      std::unique_ptr<int> p2 = std::make_unique<int>(20);
      p2 = p1 // Error assignment not allowd
      p2 = std::move(p1);
      if (!p1)
        std::cout << "p1 is now nullptr" << std::endl;
    } // automatically deleted

*/

#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include "Account.h"
#include "Saving_account.h"
#include "Checking_account.h"
#include "Trust_account.h"
#include "Account_util.h"

int main()
{
  std::vector<std::unique_ptr<Account>> accounts;
  accounts.push_back(std::make_unique<Checking_account>("James", 1000));
  accounts.push_back(std::make_unique<Saving_account>("Billy", 4000, 5.2));
  accounts.push_back(std::make_unique<Trust_account>("Bobby", 4000, 4.5));

  // here you have to use &ptr to avoid making a copy of the pointer otherwise you will receive an error.
  for (const auto &ptr: accounts) {
    ptr->deposit(2000);
    ptr->withdraw(1000);
    std::cout << *ptr << std::endl;
  }

  return 0;
}
