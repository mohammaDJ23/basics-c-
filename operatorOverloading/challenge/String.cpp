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

String String::operator-() const
{
  char *buff = new char[std::strlen(this->str) + 1];
  std::strcpy(buff, this->str);
  for (size_t i {0}; i < std::strlen(buff); i++)
    buff[i] = std::tolower(buff[i]);
  String temp {buff};
  delete[] buff;
  return temp;
}

bool String::operator==(const String &obj) const
{
  return std::strcmp(this->str, obj.str) == 0;
}

bool String::operator!=(const String &obj) const
{
  return std::strcmp(this->str, obj.str) != 0;
}

bool String::operator>(const String &obj) const
{
  return std::strcmp(this->str, obj.str) > 0;
}

bool String::operator<(const String &obj) const
{
  return std::strcmp(this->str, obj.str) < 0;
}

String &String::operator++()
{
  if (this->str == nullptr)
    return *this;

  for (size_t i {0}; i < std::strlen(this->str); i++)
    this->str[i] = std::toupper(this->str[i]);

  return *this;
}

String &String::operator++(int)
{
  return this->operator++();
}
