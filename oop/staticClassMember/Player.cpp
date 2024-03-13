#include <iostream>
#include "Player.h"

// the best place is here to define the default value of an static variable
int Player::player_count {0};

Player::Player()
  : Player{"None", 0}
{}

Player::Player(std::string n)
  : Player{n, 0}
{}

Player::Player(int h)
  : Player{"None", h}
{}

Player::Player(std::string n, int h)
  : name{n}, health{h}
{
  increment_player_cout();
}

Player::Player(const Player &source)
{}

Player::Player(Player &&source)
{}

Player::~Player()
{
  decrement_player_cout();
}

void Player::increment_player_cout()
{
  ++player_count;
}

void Player::decrement_player_cout()
{
  --player_count;
}

int Player::get_player_count()
{
  return player_count;
}

void Player::display_player_count()
{
  std::cout << Player::get_player_count() << std::endl;
}

std::string Player::get_name() const
{
  return name;
}

void Player::set_name(std::string n)
{
  name = n;
}

int Player::get_health() const
{
  return health;
}

void Player::set_health(int h)
{
  health = h;
}
