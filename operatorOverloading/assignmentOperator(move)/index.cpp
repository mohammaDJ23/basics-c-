/*

  c++ provides a default assignment operator used for assigning one object to another.

  instead of using copy assignment for temp objects,
  you use move assignment operator which is more efficient.
  becuase it does not create another story. what it does is to moving heap resource.

  if you don't provide the move assignemnt, the default behavior is to using copy assignment operator.

  String &String::operator=(String &&rhs);

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

  // str2 = str1;

  // "This is a test." needs to be created at the first time.
  // then it will use move assignment operator if you have provided it to 
  // move the heap resource from temp object to the str2.
  // after the move assignment operator then the destructor method will call for the temp object.
  // it's important to null out the temp object pointer
  // becuase at destructoring the temp object will be check if the pointer is nullptr.
  str2 = "This is a test."; // str2.operator=("This is a test.");
  
  String str3;
  
  str3 = String{"Terra"};

  String str4 {str2};

  str1.display();
  str2.display();
  str4.display();

  std::vector<String> vec;

  vec.push_back(String{"John"});
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
