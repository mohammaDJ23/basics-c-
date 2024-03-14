#ifndef _MOVIE_H_
#define _MOVIE_H_

#include <string>

class Movie
{
private:
  std::string name;
  std::string rating;
  int watch;

public:
  Movie(std::string name, std::string rating, int watch);
  Movie(const Movie &movie);
  Movie(Movie &&movie);
  ~Movie();

  std::string get_name() const;
  void set_name(std::string name);

  std::string get_rating() const;
  void set_rating(std::string rating);

  int get_watch() const;
  void set_watch(int watch);

  void increment_watch();
  void display() const;
};

#endif
