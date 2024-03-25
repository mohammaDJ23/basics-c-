/*

  A virtual function (also known as virtual methods) is a member function 
  that is declared within a base class and is re-defined (overridden) by a derived class. 
  When you refer to a derived class object using a pointer or a reference to the base class, 
  you can call a virtual function for that object and execute the derived class’s version of the method.

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
};

class Checking_account: public Account
{
public:
  virtual void withdraw(double amount) const
  {
    std::cout << "In Checking_account withdraw" << std::endl;
  }
};

class Saving_account: public Account
{
public:
  virtual void withdraw(double amount) const
  {
    std::cout << "In Saving_account withdraw" << std::endl;
  }
};

class Trust_account: public Account
{
public:
  virtual void withdraw(double amount) const
  {
    std::cout << "In Trust_account withdraw" << std::endl;
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
