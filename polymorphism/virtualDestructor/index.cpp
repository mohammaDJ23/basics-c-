/*

  - problems can happen when we destroy polymorphic objects

  - if a derived class is destroyed by deleting its storage via the base class pointer
  and the class a non-virtual destructor. then the behavior is undefined in the c++ standard.

  - derived objects must be destroyed in the correct order starting at the correct destructor.

  - solution/rules
    - if a class has virtual functions
    - always provide a public virtual destructor
    - if base class destructor is virtual then all derived class destructors are also virtual

  class Account {
  public:
    virtual void withdraw(double amount);
    virtual ~Account();
  }

*/

#include <iostream>
#include <vector>

class Account
{
public:
  virtual void withdraw(double amount) const
  {
    std::cout << "In Account withdraw" << std::endl;
  }

  virtual ~Account()
  {
    std::cout << "In Account destructor" << std::endl;
  }
};

class Checking_account: public Account
{
public:
  virtual void withdraw(double amount) const
  {
    std::cout << "In Checking_account withdraw" << std::endl;
  }

  virtual ~Checking_account()
  {
    std::cout << "In Checking_account destructor" << std::endl;
  }
};

class Saving_account: public Account
{
public:
  virtual void withdraw(double amount) const
  {
    std::cout << "In Saving_account withdraw" << std::endl;
  }

  virtual ~Saving_account()
  {
    std::cout << "In Saving_account destructor" << std::endl;
  }
};

class Trust_account: public Account
{
public:
  virtual void withdraw(double amount) const
  {
    std::cout << "In Trust_account withdraw" << std::endl;
  }

  virtual ~Trust_account()
  {
    std::cout << "In Trust_account destructor" << std::endl;
  }
};

int main()
{
  std::cout << "Pointers ===============" << std::endl;

  Account *ptr1 = new Account();
  Account *ptr2 = new Checking_account();
  Account *ptr3 = new Saving_account();
  Account *ptr4 = new Trust_account();

  ptr1->withdraw(1000);
  ptr2->withdraw(1000);
  ptr3->withdraw(1000);
  ptr4->withdraw(1000);

  std::cout << "Arrays ===============" << std::endl;

  Account *array[] {ptr1, ptr2, ptr3, ptr4};

  for (int i {0}; i < 4; i++)
    array[i]->withdraw(1000);

  std::cout << "Vectors ===============" << std::endl;

  std::vector<Account*> vec {ptr1, ptr2, ptr3, ptr4};
  
  for (const auto *ptr: vec)
    ptr->withdraw(1000);

  delete ptr1;
  delete ptr2;
  delete ptr3;
  delete ptr4;

  return 0;
}
