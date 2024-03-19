#include <iostream>
#include <cctype>
#include <cstring>
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

String::String(String &&source)
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

String &String::operator=(String &&obj)
{
  if (this == &obj)
    return *this;
  
  delete[] this->str;
  this->str = obj.str;
  obj.str = nullptr;
  return *this;
}

String operator-(const String &obj)
{
  char *buff = new char[std::strlen(obj.str) + 1];
  std::strcpy(buff, obj.str);
  for (size_t i {0}; i < std::strlen(buff); i++)
    buff[i] = std::tolower(buff[i]);
  String temp {buff};
  delete[] buff;
  return temp;
}

bool operator==(const String &lhs, const String &rhs)
{
  return std::strcmp(lhs.str, rhs.str) == 0;
}

bool operator!=(const String &lhs, const String &rhs)
{
  return std::strcmp(lhs.str, rhs.str) != 0;
}

bool operator>(const String &lhs, const String &rhs)
{
  return std::strcmp(lhs.str, rhs.str) > 0;
}

bool operator<(const String &lhs, const String &rhs)
{
  return std::strcmp(lhs.str, rhs.str) < 0;
}

String &operator++(String &obj)
{
  if (obj.str == nullptr)
    return obj;

  for (size_t i {0}; i < std::strlen(obj.str); i++)
    obj.str[i] = std::toupper(obj.str[i]);

  return obj;
}

String operator++(String &obj, int)
{
  String old {obj.str};
  ++obj;
  return old;
}

String &operator--(String &obj)
{
  if (obj.str == nullptr)
    return obj;

  for (size_t i {0}; i < std::strlen(obj.str); i++)
    obj.str[i] = std::tolower(obj.str[i]);

  return obj;
}

String operator--(String &obj, int)
{
  String old {obj.str};
  --obj;
  return old;
}

String operator+(const String &lhs, const String &rhs)
{
  char *buff = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
  std::strcpy(buff, lhs.str);
  std::strcat(buff, rhs.str);
  String temp {buff};
  delete[] buff;
  return temp;
}

String &operator+=(String &lhs, const String &rhs)
{
  lhs = lhs + rhs;
  return lhs;
}

String operator*(const String &obj, int num)
{
  /*
  
    String temp;
    for (int i = 0; i < num; i++)
      temp += obj;
    return temp;
  
  */  
  char *buff = new char[(std::strlen(obj.str) * num) + 1];
  std::strcpy(buff, "");

  for (int i {0}; i < num; i++)
    std::strcat(buff, obj.str);

  String temp {buff};
  delete[] buff;
  return temp;
}

String &operator*=(String &obj, int num)
{
  obj = obj * num;
  return obj;
}

void String::display()
{
  std::cout << this->str << std::endl;
}
