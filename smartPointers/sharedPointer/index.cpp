/*

  shared_ptr

  - provides shared ownership of heap objects

  - shared_ptr<T>
    - points to an object of type T on the heap
    - it is not unique. there can many shared_ptrs pointing to the same object on the heap
    - establishes shared ownership relationship
    - can be assign and copied
    - can be moved
    - pointer arithmetic not supported (++, --, etc)
    - does not support managing arrays by default
    - when the use count is zero, the managed object on the heap is destroyed
    - use_count => the number of shared_ptr objects managing the heap object
    - ptr.use_count() shows the number of pointers connected to the heap
    - if ptr.use_cout() is zero it means ptr is nullptr and it is not pointing to the heap

  - example:
    {
      std::shared_ptr<int> p1 {new int {10}};
      *p1 = 100;
      std::cout << *p1 << std::endl; // 100
    } // automatically deleted

  - example:
    {
      std::shared_ptr<int> p1 {new int {100}};
      std::cout << p1.use_count() << std::endl; // 1

      std::shared_ptr<int> p2 {p1};
      std::cout << p1.use_count() << std::endl; // 2
      std::cout << p2.use_count() << std::endl; // 2

      p1.reset(); // decrement the use_count; p1 is nulled out
      std::count << p1.use_count() << std::endl; // 0
      std::count << p2.use_count() << std::endl; // 1
    } // automatically deleted

  - example:
    {
      std::shared_ptr<Account> p1 {std::make_shared<Account>("Larry")};
      std::cout << *p1 << std::endl; // display account
      p1->deposit(1000);
      p1->withdraw(1000);
    } // automatically deleted
  
  - example:
    {
      std::vector<std::shared_ptr<int>> vec;
      std::shared_ptr<int> p1 {std::make_shared<int>(10)};
      vec.push_back(p1); // OK - copy is allowd
      std::cout << ptr.use_count() << std::endl; // 2
    } // automatically deleted

  - example:
    in this example when you goes out of the scope:
    p3 and p2 will be nullout then the allocated data in the heap exist yet
    becuase the p1 still holds the data and this is the last one.
    then the heap will be deleted then p1 will be nullout.
    all the example is the same when you have multiple pointer pointed to the same heap.
    {
      std::shared_ptr<int> p1 {std::make_shared<int>(100)}; // use_count: 1
      std::shared_ptr<int> p2 {p1}; // use_count: 2
      std::shared_ptr<int> p3;
      p3 = p1; // use_count: 3
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

void func(std::shared_ptr<int> ptr)
{
  std::cout << "Use count: " << ptr.use_count() << std::endl;
}

int main()
{
  std::shared_ptr<int> p1 {std::make_shared<int>(100)};
  func(p1);
  std::cout << "Use count: " << p1.use_count() << std::endl;
  {
    std::shared_ptr<int> p2 {p1};
    std::cout << "Use count: " << p1.use_count() << std::endl;
    {
      std::shared_ptr<int> p3;
      p3 = p1;  // Assigning p1 to p3
      std::cout << "Use count: " << p1.use_count() << std::endl;
      p1.reset();
    }
    std::cout << "Use count: " << p1.use_count() << std::endl;
    std::cout << "Use count: " << p2.use_count() << std::endl;
  }
  std::cout << "Use count: " << p1.use_count() << std::endl;


  std::shared_ptr<Account> ptr1 {std::make_shared<Checking_account>("James", 1000)};
  std::shared_ptr<Account> ptr2 {std::make_shared<Saving_account>("Billy", 4000, 5.2)};
  std::shared_ptr<Account> ptr3 {std::make_shared<Trust_account>("Bobby", 4000, 4.5)};

  std::vector<std::shared_ptr<Account>> accounts;
  accounts.push_back(ptr1); // Making copy
  accounts.push_back(ptr2); // Making copy
  accounts.push_back(ptr3); // Making copy

  for (const auto &ptr: accounts) {
    ptr->deposit(2000);
    ptr->withdraw(1000);
    std::cout << *ptr << std::endl;
  }

  // the destructoring will work this way:
  // nulling out all the copied ptrs in the vector
  // then ptr3 and ptr2, but the ptr1 still refer to the heap and the allocated heap still exist
  // then heap will be deallocate then ptr1 will be null out.

  return 0;
}
