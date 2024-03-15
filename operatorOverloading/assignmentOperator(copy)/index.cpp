/*

  c++ provides a default assignment operator used for assigning one object to another.

  default is memberwise assignment (shallow copy).
  if we have raw pointer data member, we must deep copy.

  String &String::operator=(const String &rhs);

  s2 = s1; // we write this

  s2.operator=(s1)/ operator= method is called

*/

#include <iostream>
#include "String.h"
#include <string>

int main()
{
  String str1 {"hey"};
  String str2;

  str2 = str1;

  return 0;
}
