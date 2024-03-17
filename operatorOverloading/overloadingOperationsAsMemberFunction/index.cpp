/*

  all these operation can be customize, because at some projects
  you may use your own logic for == or + operator.

  Unary operators as member methods (++, --, -, !)

  ReturnType Type::operatorOp();

  Number Number::operator-() const;
  Number Number::operator++();
  Number Number::operator++(int);
  Number Number::operator!() const;

  Number n1 {100};
  Number n2 = -n1; => n1.operator-()
  n2 = ++n1; => n1.operator++()
  n2 = n1++; => n1.operator++(int)


  Binary operator as member methods (+, -, ==, !=, <, >, etc)

  ReturnType Type::operatorOp(const Type &source);

  Number Number::operator+(const Number &source) const;
  Number Number::operator-(const Number &source) const;
  Number Number::operator==(const Number &source) const;
  Number Number::operator<(const Number &source) const;

  Number n1 {100}, n2 {200};
  Number n3 = n1 + n2; => n1.operator+(n2)
  n3 = n1 - n2; => n1.operator-(n2)
  if (n1 == n2) => n1.operator==(n2)


  String x {"hey"};

  String y = "Moe" + x; // this will not work with operator function as a member of a class.

*/

#include <iostream>
#include <string>
#include <vector>
#include "String.h"

int main()
{
  String str1 {"hey"};
  String str2;

  str2 = str1;

  str2 = "This is a test";
  
  String str3;
  
  str3 = String{"TERRA"};

  str1 = -str3;

  if (str1 == str2) {}

  // this line will execute
  // 1. creates all r-values string object
  // 2. - operator for -String{"For you"}
  // 3. + operator from left to right
  str1 = str1 + " " + str2 + " " + str3 + " " + -String{"For you"};

  str1.display();

  return 0;
}
