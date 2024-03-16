/*

  c++ provides a default assignment operator used for assigning one object to another.

  default is memberwise assignment (shallow copy).
  if we have raw pointer data member, we must deep copy.

  String &String::operator=(const String &rhs);

  s2 = s1; // we write this

  s2.operator=(s1) // operator= method is called

*/

#include <iostream>
#include <string>
#include <vector>
#include "String.h"

int main()
{
  String str1 {"hey"};
  String str2;

  str2 = str1;

  // "This is a test." needs to be created at the first time.
  // then it will use copy assignment operator to copy it to the str2 with different location.
  // after the copy assignment operator then the destructor method will call for the temp object.
  str2 = "This is a test."; // str2.operator=("This is a test.");

  String str3 {str2};

  str1.display();
  str2.display();
  str3.display();

  std::vector<String> vec;

  vec.push_back("Larry");
  vec.push_back("Moe");
  vec.push_back("Curly");
  vec.push_back(str2);

  for (const String &str: vec)
    str.display();
  
  for (String &str: vec)
    str = "changed";

  for (const String &str: vec)
    str.display();

  return 0;
}
