#include <iostream>
#include <vector>
#include <string>

class Player 
{
  std::string name {"Player"};
  int health {100};
  int xp {3};

  bool is_dead();
  void talk(std::string);
};

int main()
{
  Player person1;
  Player person2;

  std::vector<Player> players {person1};
  players.push_back(person2);

  Player players_arr[] {person1, person2};

  Player *player_ptr1 = new Player;
  delete player_ptr1;

  return 0;
}
