/*

  - class and struct is almost the same thing.

  - by default all thr properties of an struct is public but a class is private.

  - struct comes from c language.

  - use struct for passive object with public access.

  - do not define method in the struct.

  - use classes for active object with private access

*/

#include <iostream>
#include <string>

struct PersonS
{
  std::string name;
  int health;
};

class PersonC
{
  std::string name;
  int health;
};


int main()
{
  PersonS person1;
  person1.name = "Jack";
  person1.health = 100;

  PersonC person2;
  // person2.name = "Moe"; // error
  // person2.health = 100; // error

  return 0;
}
