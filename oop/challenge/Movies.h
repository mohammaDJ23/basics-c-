#ifndef _MOVIES_H_
#define _MOVIES_H_

#include <string>
#include <vector>
#include "Movie.h"

class Movies
{
private:
  std::vector<Movie> *movies;

public:
  Movies();
  ~Movies();

  void add_new(std::string name, std::string rating, int watch);
  bool is_exist(std::string name) const;
  int get_index(std::string name) const;
  void increment_watch(std::string name);
  bool is_empty() const;
  void display() const;
};

#endif
