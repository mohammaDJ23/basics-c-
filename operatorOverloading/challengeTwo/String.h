#ifndef _STRING_H_
#define _STRING_H_

class String
{
  friend String operator-(const String &obj);
  friend bool operator==(const String &lhs, const String &rhs);
  friend bool operator!=(const String &lhs, const String &rhs);
  friend bool operator<(const String &lhs, const String &rhs);
  friend bool operator>(const String &lhs, const String &rhs);
  friend String &operator++(String &obj);
  friend String operator++(String &obj, int);
  friend String &operator--(String &obj);
  friend String operator--(String &obj, int);
  friend String operator+(const String &lhs, const String &rhs);
  friend String &operator+=(String &lhs, const String &rhs);
  friend String operator*(const String &obj, int num);
  friend String &operator*=(String &obj, int num);

private:
  char *str;

public:
  String();
  String(const char *const str);
  String(const String &source);
  String(String &&source);
  ~String();

  String &operator=(const String &rhs);
  String &operator=(String &&rhs);

  void display();
};

#endif