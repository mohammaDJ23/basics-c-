#include <iostream>

void print_hello_world(void);
int get_num(int i); // or int get_str(int);

int main()
{
  print_hello_world();
  std::cout << get_num(1) << std::endl;
  return 0;
}

void print_hello_world()
{
  std::cout << "Hello world." << std::endl;
}

int get_num(int i)
{
  return i;
}
