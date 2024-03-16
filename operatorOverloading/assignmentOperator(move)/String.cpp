#include <cstring>
#include <iostream>
#include "String.h"

String::String()
  : str{nullptr}
{
  this->str = new char[1];
  *this->str = '\0';
  std::cout << "String created with address " << this << " and the str pointer contains '" << this->str << "'." << std::endl;
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
  std::cout << "String created with address " << this << " and the str pointer contains '" << this->str << "'." << std::endl;
}

String::String(const String &source)
  : String{source.str}
{}

String::String(String &&source)
  : str{source.str}
{
  source.str = nullptr;
}

// assignment operator overloading (copy assignment) 
// deep copy becuase a pointer exist in the class.
String &String::operator=(const String &source)
{
  // check if the source is the current
  if (this == &source)
    return *this;

  // release the allocated memory
  std::cout << "String with address " << this << " which contains '" << this->str << "' is deallocating..." << std::endl;
  delete[] this->str;
  std::cout << "Deallocated." << std::endl;

  // allocate a new space
  this->str = new char[std::strlen(source.str) + 1];
  std::strcpy(this->str, source.str);
  std::cout << "A new allocation is done." << std::endl;

  return *this;
}

// assignment operator overloading (move assignment)
String &String::operator=(String &&source)
{
  // check if the source is the current
  if (this == &source)
    return *this;

  // release the allocated memory
  std::cout << "String with address " << this << " which contains '" << this->str << "' is deallocating..." << std::endl;
  delete[] this->str;
  std::cout << "Deallocated." << std::endl;

  // pointing to the source str on heap
  std::cout << "Pointing to the new space on heap by the temp object..." << std::endl;
  this->str = source.str;
  std::cout << "Pointed." << std::endl;

  // null out the source. this part is really important.
  // if you don't this, at destructor, the allocated heap will be destory.
  // also see the destructor method.
  std::cout << "Nulling out the source pointer..." << std::endl;
  source.str = nullptr;
  std::cout << "Nulled out." << std::endl;

  return *this;
}

String::~String()
{
  delete[] this->str;
  
  if (this->str == nullptr)
    std::cout << "String destroyed for the str pointer which is nullptr." << std::endl;
  else
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
