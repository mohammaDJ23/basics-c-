/*

  if you define an static variable in a function,
  if you call the function multiple time,
  you won't lose the static variable value in the further functions.
  it is work like a global variable but it's inside an scope.

  for exmaple:
  if you call the first function and set the static variable to 10,
  if you call the second function,
  you get 10 from the previous function and you set it to 20;

*/

#include <iostream>

void calc_with_static_var(int n)
{
  static int num {0};
  std::cout << "The num with static sign is: " << num << std::endl;
  std::cout << "changing... " << num << std::endl;
  num += n;
  std::cout << "The num with static sign after changing is: " << num << std::endl;
}

int main()
{
  calc_with_static_var(10);
  calc_with_static_var(20);
  calc_with_static_var(30);

  return 0;
}
