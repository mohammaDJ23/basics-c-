#include <iostream>
#include "String.h"
#include <string>

int main()
{
  String str1;
  String str2 {"hey"};
  String str3 {str2};

  str1.display();
  str2.display();
  str3.display();

  return 0;
}
