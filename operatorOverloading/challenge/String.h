#ifndef _STRING_H_
#define _STRING_H_

class String
{
private:
  char *str;

public:
  String();
  String(const char *const str);
  String(const String &source);
  String(String &&source);
  ~String();

  String &operator=(const String &obj);
  String &operator=(String &&obj);
  String operator-() const;
  bool operator==(const String &rhs) const;
  bool operator!=(const String &rhs) const;
  bool operator<(const String &rhs) const;
  bool operator>(const String &rhs) const;
  String &operator++();
  String operator++(int);
  String &operator--();
  String operator--(int);
  String operator+(const String &rhs) const;
  String &operator+=(const String &rhs);
  String operator*(int num) const;
  String &operator*=(int num);

  void display();
};

#endif