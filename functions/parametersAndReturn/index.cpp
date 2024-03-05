/*

  the functions parameters will not change the actual argument without referencing and
  just will change the local parameter.
  a function will make a copy from the actual argument.

*/

#include <iostream>
#include <string>
#include <vector>

void change_num(int i)
{
  i = 1000;
}

void change_vec(std::vector<std::string> vec)
{
  vec.clear();
}

int main()
{
  int num {10};

  std::cout << "num before changing is: " << num << std::endl;
  change_num(num);
  std::cout << "num after changing is: " << num << std::endl;

  std::cout << std::endl;

  std::vector<std::string> vec {"Moe", "Jack"};

  std::cout << "vec before changing is: ";
  for (auto str : vec)
    std::cout << str << " ";
  std::cout << std::endl;
  change_vec(vec);
  std::cout << "vec after changing is: ";
  for (auto str : vec)
    std::cout << str << " ";
  std::cout << std::endl;

  return 0;
}
