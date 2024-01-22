/*
*
* ask a user two numbers!
*
*/

#include <iostream>

int main()
{
  /* 
    solution one
  */

  int num1;
  int num2;

  std::cout << "Enter two number separated with a space: ";
  std::cin >> num1 >> num2;
  std::cout << "The first number is" << " " << num1 << " " << "and the second is" << " " << num2 << "." << std::endl;

  /* 
    solution two
    but the use puts both number at the first cout like: 100 200
    the second cin would not work because the 200 has been inserted as the second cin.  
  */

  int num3;
  int num4;

  std::cout << "Enter the first number: ";
  std::cin >> num3;
  std::cout << "Enter the second number: ";
  std::cin >> num4;
  std::cout << "The first number is" << " " << num3 << " " << "and the second is" << " " << num4 << "." << std::endl;

  /*
    solution three
    imgine you enter "10 20.5". this works fine.
    but if you put "10.5 20.5" as the first number.
    the result would be "10 0.5". means that you ask the user put the first input as an int
    but cin check the 10 and when it reachs to ".", it would not consider as an int. 
    since you as the second number as a double, cin will consider ".5" as "0.5" as an double and then cin
    will not reach to "20.5" because there is a spance between those two numbers and the cin has picked the second number
    which was "0.5".
    the same issue will occure in the solution one and two.
  */

  int num5;
  double num6;

  std::cout << "Enter two number separated with a space, one an int and the second a double: ";
  std::cin >> num1 >> num2;
  std::cout << "The first number is" << " " << num1 << " " << "and the second is" << " " << num2 << "." << std::endl;

  return 0;
}