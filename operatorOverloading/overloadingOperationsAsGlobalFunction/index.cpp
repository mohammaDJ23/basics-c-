/*

  all these operation can be customize, because at some projects
  you may use your own logic for == or + operator.

  Unary operators as member methods (++, --, -, !)

  ReturnType operatorOp(Type &obj);

  Number operator-(const Number &obj);
  Number operator++(Number &obj);
  Number operator++(Number &obj, int);
  Number operator!(const Number &obj);

  Number n1 {100};
  Number n2 = -n1; => operator-(n1)
  n2 = ++n1; => operator++(n1)
  n2 = n1++; => operator++(n1, int)


  Binary operator as member methods (+, -, ==, !=, <, >, etc)

  ReturnType operatorOp(const Type &lhs, const Type &rhs);

  Number operator+(const Number &lhs, const Number &rhs);
  Number operator-(const Number &lhs, const Number &rhs);
  Number operator==(const Number &lhs, const Number &rhs);
  Number operator<(const Number &lhs, const Number &rhs);

  Number n1 {100}, n2 {200};
  Number n3 = n1 + n2; => operator+(n1, n2)
  n3 = n1 - n2; => operator-(n1, n2)
  if (n1 == n2) => operator==(n1, n2)


  String x {"hey"};

  String y = "Moe" + x; // now this will work with operator function as global method and using friend in a class.

*/

#include <iostream>
#include <string>
#include <vector>
#include "String.h"

int main()
{
  String larry {"Larry"};
  larry.display();

  larry = -larry;
  larry.display();

  String larry1 {"heey"};

  std::cout << std::boolalpha;
  std::cout << (larry == larry1) << std::endl;

  String stooge1 = "Moe" + larry1;
  String stooge2 {"Jack" + larry1};
  String stooge3 {larry1};
  String stooge4 {String{"Ohhha"}};

  return 0;
}
