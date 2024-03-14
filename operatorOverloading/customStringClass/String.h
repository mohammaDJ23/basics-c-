#ifndef _STRING_H_
#define _STRING_H_

class String
{
private:
  char *str;

public:
  String();
  String(const char *str);
  String(const String &source);
  ~String();
  
  void display() const;
  int get_length() const;
  const char *get_str() const;
};

#endif
