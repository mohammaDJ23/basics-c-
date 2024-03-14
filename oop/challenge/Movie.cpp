#include <iostream>
#include "Movie.h"

Movie::Movie(std::string name, std::string rating, int watch)
  : name{name}, rating{rating}, watch{watch}
{}

Movie::Movie(const Movie &movie)
  : Movie{movie.name, movie.rating, movie.watch}
{}

Movie::Movie(Movie &&movie)
  : name{movie.name}, rating{movie.rating}, watch{movie.watch}
{
  movie.name = "";
  movie.rating = "";
  movie.watch = 0;
}

Movie::~Movie()
{}

std::string Movie::get_name() const 
{
  return this->name;
}

void Movie::set_name(std::string name) 
{
  this->name = name;
}

std::string Movie::get_rating() const 
{
  return this->rating;
}

void Movie::set_rating(std::string rating) 
{
  this->rating = rating;
}

int Movie::get_watch() const 
{
  return this->watch;
}

void Movie::set_watch(int watch) 
{
  this->watch = watch;
}

void Movie::increment_watch()
{
  ++this->watch;
}

void Movie::display() const
{
  std::cout << this->get_name() << ", " 
    << this->get_rating() << ", " << this->get_watch() << std::endl;
}