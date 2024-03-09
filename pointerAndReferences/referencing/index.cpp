/*

  referencing means we create a new variable 
  then we assing to another variable which the new variable is not copying that one.
  that means by referencing we access to the actual variable by the new one without consume more memory space.
  this is great when we have a large data structure which consume really big space.

  if we change the actual variable or new reference, the actual variable will change
  and both of them have the same value.

  referencing is an alias to the actual variable. 
  so any change to it, the actual variable will change or vice versa.

*/

#include <iostream>
#include <vector>
#include <string>

int main()
{
  int num {100};
  int &num_ref {num};

  std::cout << "num is: " << num << std::endl;
  std::cout << "&num_ref is: " << num_ref << std::endl;

  std::cout << "changing num to 200..." << std::endl;
  num = 200;

  std::cout << "num is: " << num << std::endl;
  std::cout << "&num_ref is: " << num_ref << std::endl;

  std::cout << "changing &num_ref to 300..." << std::endl;
  num_ref = 300;

  std::cout << "num is: " << num << std::endl;
  std::cout << "&num_ref is: " << num_ref << std::endl;

  std::vector<std::string> vec_str {"Jack", "Frank", "Moe"};

  for (auto str: vec_str)
    str = "Funny"; // this will not any affect to vec_str since str is changing to Funny.

  for (auto str: vec_str)
    std::cout << str << " ";
  std::cout << std::endl;

  for (auto &str: vec_str)
    str = "Funny"; // this will affect to vec_str since str is a reference to each element in vec_str.
  
  for (const auto &str: vec_str)
    std::cout << str << " ";
  std::cout << std::endl;

  return 0;
}
