/*

  - constructors:
    - special member method
    - invoked during object creation
    - useful for initialization
    - same name as the class
    - no return type is specified
    - can be overloaded
    - the initialization is:
      - Player player;
      - Player player(name);
      - Player player{name, age};
      - Player *player = new Player{name, age, xp};
      - Player *player = new Player(name, ex);

  - destructors
    - special member method
    - same name as the class proceeded with a tilde (~)
    - invoked automatically when an object is destroyed
    - no return type and no parameters
    - only 1 destructor is allowed per class - can not be overloaded
    - useful to release memory and other resources
    - if a variable initialized in an scope or an stack, when the program goes after those scope, this method will call
    - called when memory is released (with delete keyword for a pointer)
    - if for example three classes defined in an scope, after the scope, destructor will call from 3 to 1, from bottom to up.

*/

#include <iostream>
#include <string>

class Player
{
private:
  std::string name;
  int health;
  int xp;

public:
  // constructors methods

  Player()
  {
    std::cout << "No argument constructor called." << std::endl;
  }

  Player(std::string name)
  {
    std::cout << "Constructor with the name argument called." << std::endl;
  }

  Player(std::string name, int health, int xp)
  {
    std::cout << "Constructor with the name, health and xp argument called." << std::endl;
  }

  Player(int health, int xp)
  {
    std::cout << "Constructor with the health and xp argument called." << std::endl;
  }

  // destructor method

  ~Player()
  {
    std::cout << name << " is destroying the class..." << std::endl;
  }

  // other methods

  void set_name(std::string n)
  {
    name = n;
  }
};

int main()
{
  {
    Player person;
    person.set_name("mohammad nowresideh");
  } // the destroy function will work after this block becuase person inside this block

  {
    Player person1;
    person1.set_name("Jack");

    Player person2;
    person2.set_name("Mike");

    Player person3;
    person3.set_name("Moe");
  } // the destroy function will work after this block from person3 to person1

  Player *enemy = new Player("Larry");
  enemy->set_name("Sara");
  delete enemy; // the destroy function will call here

  Player *player = new Player{"Nilou", 100, 100};
  player->set_name("Nilou");
  delete player; // the destroy function will call here

  return 0;
}
