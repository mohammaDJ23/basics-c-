/*

  for accessing an object by a pointer we have two syntax:

  Player *player_ptr1 = new Player;

  (*player_ptr1).name = "Jack";
  player_ptr1->name = "Jack";

  delete player_ptr1;

*/

#include <iostream>
#include <vector>
#include <string>

class Player 
{
public:
  std::string name;
  int health;
  int xp;

  bool is_dead()
  {
    return health <= 0;
  }

  void talk(std::string text)
  {
    std::cout << name << " says " << text << std::endl;
  }
};

class Accout
{
public:
  std::string name;
  double balance;

  void deposit(double val)
  {
    balance += val;
  }

  void withdraw(double val)
  {
    balance -= val;
  }
};

int main()
{
  Player person;

  person.name = "Frank";
  person.health = 100;
  person.xp = 3;
  person.is_dead();
  person.talk("hey!!");

  Player *player_ptr1 = new Player;

  player_ptr1->name = "Jack";
  player_ptr1->health = 88;
  player_ptr1->xp = 5;
  player_ptr1->is_dead();
  player_ptr1->talk("hey!!");

  delete player_ptr1;

  Accout person_accout;

  person_accout.name = "Mohammad";
  person_accout.balance = 5000.0;
  person_accout.deposit(1000.0);
  person_accout.withdraw(500.0);

  return 0;
}
