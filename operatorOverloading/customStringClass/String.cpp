#include <cstring>
#include <iostream>
#include "String.h"

String::String()
  : str{nullptr}
{
  str = new char[1];
  *str = '\0';
}

String::String(const char *const str)
  : str{nullptr}
{
  if (str == nullptr) {
    this->str = new char[1];
    *this->str = '\0';
  } else {
    this->str = new char[std::strlen(str) + 1];
    std::strcpy(this->str, str);
  }
}

String::String(const String &source)
  : String{source.str}
{}

String::~String()
{
  delete[] str;
}

void String::display() const
{
  std::cout << this->get_length() << " " << this->get_str() << std::endl;
}

int String::get_length() const
{
  return std::strlen(this->str);
}

const char *String::get_str() const
{
  return this->str;
}
