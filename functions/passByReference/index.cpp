/*

  when you pass a reference to a function you actually deal with the actual variable 
  for example to print or manipulate it
  and function won't make another copy of the variable.
  this is so important when the variable consume a lot memoy to avoid coppying.
  if you pass a reference to a function that you won't to manipulate it, 
  just use it as a constant see the print_vec function

  we use & sign.

*/

#include <iostream>
#include <string>
#include <vector>

void change_num(int &i);
void change_vec(std::vector<std::string> &vec);
void print_vec(const std::vector<std::string> &vec);

int main()
{
  int num {10};

  std::cout << "num before changing is: " << num << std::endl;
  change_num(num);
  std::cout << "num after changing is: " << num << std::endl << std::endl;

  std::vector<std::string> vec {"Moe", "Jack"};

  std::cout << "vec before changing is: ";
  print_vec(vec);
  change_vec(vec);
  std::cout << "vec after changing is: ";
  print_vec(vec);

  return 0;
}

void change_num(int &i)
{
  i = 1000;
}

void change_vec(std::vector<std::string> &vec)
{
  vec.clear();
}

void print_vec(const std::vector<std::string> &vec)
{
  for (auto str : vec)
    std::cout << str << " ";
  std::cout << std::endl;
}
