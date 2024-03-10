/*

  class member access modifier:

  public, private, protected

*/

#include <iostream>
#include <string>

class Player 
{
private:
  std::string name {"Player"};
  int health {};
  int xp {};

public:
  bool is_dead()
  {
    return health <= 0;
  }

  void talk(std::string text)
  {
    std::cout << name << " says " << text << std::endl;
  }
};

int main()
{
  Player person;

  // person.name = "Frank"; // error
  // person.health = 100; // error
  // person.xp = 3; // error
  // std::cout << person.name << std::endl; // error

  person.is_dead();
  person.talk("hey!!");

  return 0;
}
