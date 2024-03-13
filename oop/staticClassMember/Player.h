#ifndef __PLAYER_H_
#define __PLAYER_H_

#include <string>

class Player
{
private:
  static int player_count;
  std::string name;
  int health;

public:
  Player();
  Player(std::string n);
  Player(int h);
  Player(std::string n, int h);
  Player(const Player &source);
  Player(Player &&source);
  ~Player();

  static void increment_player_cout();
  static void decrement_player_cout();
  static int get_player_count();
  static void display_player_count();

  std::string get_name() const;
  void set_name(std::string n);

  int get_health() const;
  void set_health(int h);
};

#endif
