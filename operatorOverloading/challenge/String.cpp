#include <iostream>
#include <cctype>
#include <string>
#include "String.h"

String::String()
  : str{nullptr}
{
  this->str = new char[1];
  *this->str = '\0';
}

String::String(const char *const str)
  : str{nullptr}
{
  if (str == nullptr)
    String();
  else {
    this->str = new char[std::strlen(str) + 1];
    std::strcpy(this->str, str);
  }
}

