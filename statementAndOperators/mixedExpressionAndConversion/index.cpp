/*

  Mixed type expression

  * Higher vs lower types are based on the size of the values the type can hold
    * long double, double, float, unsigned long, long, unsigned int, int
    * short and char types are always converted to int
  
  * Promotion: conversion to a higher type
    * used in mathematical expressions
    * 
    * 2 * 5.2
    * 2 is promoted to 2.0
  
  * Demotion: conversion to a lower type
    * used with assignment to lower type
    * 
    * lower = higher
    * int num {0};
    * num = 100.2;
  
  * If we want to put result as a specifc type, we use std::static_cast<type>(...)

*/

#include <iostream>

int main()
{
  int num1 {1};
  double num2 {2.2};

  // promotion
  // int to double
  std::cout << num1 + num2 << std::endl;

  // demotion
  // double to int
  num1 = num2;
  std::cout << num1 << std::endl;

  // promotion
  int num3 {}, num4 {}, num5 {};
  const int counts {3};

  std::cout << "Enter 3 integers seporated by a space: ";
  std::cin >> num3 >> num4 >> num5;

  int sum {0};
  double avarege {0};
  
  sum = num3 + num4 + num5;

  // just one of these integer must be a double to prints out an accurate result
  avarege = static_cast<double>(sum) / counts;

  // do not use this old c-style
  // avarage = (double)sum / counts;

  std::cout << "integers are: " << num3 << " " << num4 << " " << num5 << std::endl;
  std::cout << "the sum of the integers is: " << sum << std::endl;
  std::cout << "the avarege of the integers is: " << avarege << std::endl;

  return 0;
}
