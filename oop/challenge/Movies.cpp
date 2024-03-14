#include <iostream>
#include <algorithm>
#include "Movies.h"
#include "Movie.h"

Movies::Movies()
{
  this->movies = new std::vector<Movie>;
  std::cout << "movies ptr contains address " << this->movies << "." << std::endl;
}

Movies::~Movies()
{
  delete this->movies;
  std::cout << "movies ptr at address " << this->movies << " destroyed." << std::endl;
}

void Movies::add_new(std::string name, std::string rating, int watch)
{
  if (this->is_exist(name))
    std::cout << name << " is already exist." << std::endl;
  else {
    (*this->movies).push_back(Movie{name, rating, watch});
    std::cout << name << " added." << std::endl;
  }
}

inline bool Movies::is_exist(std::string name) const
{
  return this->get_index(name) != -1;
}

int Movies::get_index(std::string name) const
{
  for (size_t i {0}; i < (*this->movies).size(); i++)
    if ((*this->movies).at(i).get_name() == name)
      return i;
  return -1;
}

void Movies::increment_watch(std::string name)
{
  if (this->is_exist(name)) {
    (*this->movies).at(this->get_index(name)).increment_watch();
    std::cout << name << " incremented its watch." << std::endl;
  } else
    std::cout << name << " is not found for incrementing." << std::endl;
}

inline bool Movies::is_empty() const
{
  return (*this->movies).size() <= 0;
}

void Movies::display() const
{
  if (!is_empty())
    for (auto movie: (*this->movies))
      movie.display();
  else
    std::cout << "Sorry, movies are empty." << std::endl;
}
