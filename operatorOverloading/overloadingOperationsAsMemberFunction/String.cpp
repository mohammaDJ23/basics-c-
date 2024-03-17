#include <cstring>
#include <iostream>
#include <cctype>
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

  std::cout << "Copy assignment operation for '" << this->str << "' to be '" << source.str << "'..." << std::endl;

  // release the allocated memory
  delete[] this->str;

  // allocate a new space
  this->str = new char[std::strlen(source.str) + 1];
  std::strcpy(this->str, source.str);

  return *this;
}

// assignment operator overloading (move assignment)
String &String::operator=(String &&source)
{
  // check if the source is the current
  if (this == &source)
    return *this;

  std::cout << "Move assignment operation for '" << this->str << "' to be '" << source.str << "'..." << std::endl;

  // release the allocated memory
  delete[] this->str;

  // pointing to the source str on heap
  this->str = source.str;

  // null out the source. this part is really important.
  // if you don't this, at destructor, the allocated heap will be destory.
  // also see the destructor method.
  source.str = nullptr;

  return *this;
}

// make lowercase
String String::operator-() const
{
  std::cout << "Unary operation (-) for '" << this->str << "'..." << std::endl;

  // allocating a new space
  char *buff {nullptr};
  buff = new char[std::strlen(this->str) + 1];

  // copying the actual str into the new space
  std::strcpy(buff, this->str);

  // making lowercase
  for (size_t i {0}; i < std::strlen(buff); i++)
    buff[i] = std::tolower(buff[i]);
  
  // making a new string with the new pointer
  String temp {buff};

  // removing the temp allocated space
  delete[] buff;

  return temp;
}

// concatenate
String String::operator+(const String &source) const
{
  std::cout << "Binary operation (+) for '" << this->str << "' + '" << source.str << "'..." << std::endl;

  // allocating a new space
  char *buff {nullptr};
  buff = new char[std::strlen(this->str) + std::strlen(source.str) + 1];

  // copying the actual str into the new space
  std::strcpy(buff, this->str);
  std::strcat(buff, source.str);

  // making a new string with the new pointer
  String temp {buff};

  // removing the temp allocated space
  delete[] buff;

  return temp;
}

// comparison
bool String::operator==(const String &source) const
{
  std::cout << std::boolalpha;
  return std::strcmp(this->str, source.str) == 0;
}

String::~String()
{  
  if (this->str == nullptr)
    std::cout << "Destroing string object which contians nullptr str..." << std::endl;
  else
    std::cout << "Destroing string object which contians an str address " << this << " which contains " << this->str << "..." << std::endl;

  delete[] this->str;
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
