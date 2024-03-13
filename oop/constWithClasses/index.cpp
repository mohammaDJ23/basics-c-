/*

  when some of the class methods are not going to manipulate the class attrs,
  like the getter methods, use them as const to tell compiler that they are not going to change the class attr
  otherwise compiler do not know about the methods.

  example:

  class Person {
    private:
      std::string name;
    public:
      std::string get_name();
  }
  Person::get_name() { return name; }



  const Person person1;
  person1.get_name() // this will be throw an error.



  void display_person(const Person &p)
  {
    std::cout << p.get_name() << std::endl; // this will be throw an error.
  }
  const Person person2;
  Person person3;

  display_person(person2); // error
  display_person(person3); // error



  becuase you tell compiler person1 is a constant and compiler does not know about the get_name function.
  so put a const at the end of get_name function:
  std::string get_name() const;
  with this const you tell compiler that the get_name method is not manipulating the object.

*/

#include <iostream>
#include <string>

class Account
{
private:
  std::string name;

public:
  Account(std::string n);
  Account(const Account &source);
  Account(Account &&source);
  ~Account();

  std::string get_name() const /* this is the key */;
};

Account::Account(std::string n)
  : name{n}
{
  std::cout << "Constructor" << std::endl;
}

Account::Account(const Account &source)
{
  std::cout << "Copy constructor" << std::endl;
}

Account::Account(Account &&source)
{
  std::cout << "Move constructor" << std::endl;
}

Account::~Account()
{
  std::cout << "Destructor constructor" << std::endl;
}

std::string Account::get_name() const /* this is the key */
{
  return name;
}

void display_account(const Account &a)
{
  std::cout << a.get_name() << std::endl;
}

int main()
{
  const Account account1 {"Mohammad"};
  Account account2 {"Jack"};

  display_account(account1);
  display_account(account2);

  return 0;
}
