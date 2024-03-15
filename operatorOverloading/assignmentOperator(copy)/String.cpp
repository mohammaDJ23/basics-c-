#include <cstring>
#include <iostream>
#include "String.h"

String::String()
  : str{nullptr}
{
  this->str = new char[1];
  *this->str = '\0';
  std::cout << "String created with address " << this << " and the str pointer contains " << this->str << "." << std::endl;
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
  std::cout << "String created with address " << this << " and the str pointer contains " << this->str << "." << std::endl;
}

String::String(const String &source)
  : String{source.str}
{}

// assignment operator overloading (copy assignment) 
// deep copy becuase a pointer exist in the class.
String &String::operator=(const String &source)
{
  // check if the source is the current
  if (this == &source)
    return *this;

  // release the allocated memory
  delete[] this->str;

  // allocate a new space
  this->str = new char[std::strlen(source.str) + 1];
  std::strcpy(this->str, source.str);
  return *this;
}

String::~String()
{
  delete[] this->str;
  std::cout << "String destroyed with address " << this << "." << std::endl;
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
