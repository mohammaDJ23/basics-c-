/*

  - when object are copied, c++ must create a new object from an existng object

  - when is a copy of an object made?
    - passing object by value as a parameter
    - returning an object from a function by value
    - constructing one object based on another of the same class
    all of them exist in the below example

  - c++ must have a way of accompishing this so it provides a compiler-defined copy constructor if you don't

  - if you don't provide your own way of copying objects by value then the compiler provides a default way of copying objects

  - copies the values of each data member to the new object
    - default memberwise copy

  - perfectly fine in many cases

  - beware if you have a pointer data member
    - pointer will be copied
    - not what it is pointing to
    - shallow vs deep copy - more in the next section

*/

#include <iostream>
#include <string>

class Account
{
private:
  std::string name;
  std::string type;
  double balance;

public:
  std::string get_name(void) { return name; }
  std::string get_type(void) { return type; }
  double get_balance(void) { return balance; }

  // constructor
  Account(std::string n = "Unknown", std::string t = "USD", double b = 0.0);

  // copy constructor
  Account(const Account &source);

  // destructor
  ~Account();
};

Account::Account(std::string n, std::string t, double b)
  : name{n}, type{t}, balance{b} 
{
  std::cout << name << " is initializing the constructor." << std::endl;
}

Account::Account(const Account &source)
  : Account{source.name, source.type, source.balance}
{
  std::cout << name << " is copying the constructor." << std::endl;
}

Account::~Account()
{
  std::cout << "Destructoring for " << name << " is called." << std::endl;
}

void display_player(Account account)
{
  std::cout << "name is: " << account.get_name() << std::endl;
  std::cout << "type is: " << account.get_type() << std::endl;
  std::cout << "balance is: " << account.get_balance() << std::endl;
}

Account make_account(std::string name)
{
  Account account {name};
  return account;
}

int main()
{
  Account person1;
  Account person2 {"Mohammad nowresideh"};

  display_player(person2);

  Account person3;

  person3 = make_account("Jack");

  display_player(person3);

  return 0;
}
