#ifndef _STRING_H_
#define _STRING_H_

class String
{
  friend std::ostream &operator<<(std::ostream &os, const String &obj);
  friend std::istream &operator>>(std::istream &is, String &obj);

private:
  char *str;

public:
  String();
  String(const char *const str);
  String(const String &source);
  String(String &&source);
  ~String();

  // assignment operator overloading (copy)
  String &operator=(const String &source);

  // assignment operator overloading (move)
  String &operator=(String &&source);

  void display() const;
  int get_length() const;
  const char *get_str() const;
};

#endif
