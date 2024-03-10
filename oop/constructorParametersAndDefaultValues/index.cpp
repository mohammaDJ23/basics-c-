#include <iostream>
#include <string>

class Account
{
private:
  std::string name;
  std::string type;
  double balance;

public:
  Account(std::string n = "Unknown", 
    std::string t = "USD", 
    double b = 0.0);
};

Account::Account(std::string n, std::string t, double b)
  : name{n}, type{t}, balance{b} 
{
  std::cout << "Name, type and balance arguments are called." << std::endl;
}

int main()
{
  Account person;
  Account person2 {"Mohammad nowresideh"};
  Account person3 {"Jack", "USD", 500.0};

  return 0;
}
