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
  ~String();

  // assignment operator overloading
  String &operator=(const String &source);
  
  void display() const;
  int get_length() const;
  const char *get_str() const;
};

#endif
