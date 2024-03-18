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

String::String(const String &source)
  : String{source.str}
{}

String::String(const String &&source)
  : str{source.str}
{
  source.str = nullptr;
}

String::~String()
{
  if (this->str == nullptr) {}
  else {}

  delete[] this->str;
}

String &String::operator=(const String &obj)
{
  if (this == &obj)
    return *this;
  
  delete[] this->str;
  this->str = new char[std::strlen(obj.str) + 1];
  std::strcpy(this->str, obj.str);
  return *this;
}

String &String::operator=(const String &&obj)
{
  if (this == &obj)
    return *this;
  
  delete[] this->str;
  this->str = obj.str;
  obj.str = nullptr;
  return *this;
}
