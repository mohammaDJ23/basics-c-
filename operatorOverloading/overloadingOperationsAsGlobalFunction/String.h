#ifndef _STRING_H_
#define _STRING_H_

class String
{
  // defined all these functions as a global function
  friend String operator-(const String &obj);
  friend String operator+(const String &lhs, const String &rhs);
  friend bool operator==(const String &lhs, const String &rhs);

private:
  char *str;

public:
  String();
  String(const char *const str);
  String(const String &source);
  String(String &&source);
  ~String();

  String &operator=(const String &source);
  String &operator=(String &&source);

  void display() const;
  int get_length() const;
  const char *get_str() const;
};

#endif
