#include <iostream>
#include "Movies.h"
#include "Movie.h"

int main()
{
  Movies movies;

  movies.add_new("Soul", "PG", 1);
  movies.increment_watch("Soul");
  movies.display();

  movies.add_new("Halk", "PG-13", 5);

  movies.increment_watch("See"); 

  movies.display();

  return 0;
}
