/*

  - we could have attr and method as static member of a class

  - the static attr or method is belog to a class not object

  - this is like a global attr but it is inside the class

  - the best way to define the default value of a static attr is inside the cpp file

  - the static method can only access to the static attrs

*/

#include <iostream>
#include "Player.h"

int main()
{
  Player::display_player_count();
  Player player1;
  Player::display_player_count();
  Player player2 {"Jack"};
  Player::display_player_count();

  {
    Player player3 {"Mike"};
    Player::display_player_count();
  }

  Player::display_player_count();
  Player *player4 = new Player("Moe");
  Player::display_player_count();
  delete player4;
  Player::display_player_count();

  return 0;
}
