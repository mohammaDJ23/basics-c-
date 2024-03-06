#include <iostream>
#include <string>
#include <vector>

void print(int i);
void print(double d);
void print(std::string s);
void print(std::string s1, std::string s2);
void print(std::vector<std::string> vec);

void print(int i)
{ 
  std::cout << "int is printing: " << i << std::endl;
}

void print(double d)
{ 
  std::cout << "double is printing: " << d << std::endl;
}

void print(std::string s)
{ 
  std::cout << "one string is printing: " << s << std::endl;
}

void print(std::string s1, std::string s2)
{ 
  std::cout << "two strings are printing: " << s1 << " " << s2 << std::endl;
}

void print(std::vector<std::string> vec)
{
  std::cout << "vector is printing: ";

  for (auto c : vec)
    std::cout << c << " ";
  std::cout << std::endl;
}

int main()
{
  print(1);
  print('A');
  print(2.2);
  print(2.2F);
  print("c-style string");

  std::string cpp_string {"c++ string"};
  print("c-style string", cpp_string);

  std::vector<std::string> vec {"Moe", "Jack"};
  print(vec);

  return 0;
}
