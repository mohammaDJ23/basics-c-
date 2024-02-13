/*

  it will display true and false instead of 0 and 1
  std::cout << std::boolalpha;

  

  consider that c++ will approximatly calculate the big number. for example:
  10.0 == 9.999999999999999999999999999999999999
  this will be => true



  if you comparision an int with a double, the int will promote to a double.
  int num1 {0};
  int double1 {0.0};
  num1 == double1;
  int == double => double == double => 0.0 == 0.0

*/

#include <iostream>

int main()
{
  bool equal_result {false};
  bool not_equal_result {false};

  int num1 {0};
  int num2 {0};

  std::cout << std::boolalpha;

  std::cout << "Enter two integer seperated by a space: ";
  std::cin >> num1 >> num2;
  equal_result = num1 == num2;
  not_equal_result = num1 != num2;
  std::cout << "The comparision result (equal): " << equal_result << std::endl;
  std::cout << "The comparision result (not equal): " << not_equal_result << std::endl << std::endl;

  char char1 {0};
  char char2 {0};

  std::cout << "Enter two char seperated by a space: ";
  std::cin >> char1 >> char2;
  equal_result = char1 == char2;
  not_equal_result = char1 != char2;
  std::cout << "The comparision result (equal): " << equal_result << std::endl;
  std::cout << "The comparision result (not equal): " << not_equal_result << std::endl << std::endl;

  double double1 {0.0};
  double double2 {0.0};

  std::cout << "Enter two double seperated by a space: ";
  std::cin >> double1 >> double2;
  equal_result = double1 == double2;
  not_equal_result = double1 != double2;
  std::cout << "The comparision result (equal): " << equal_result << std::endl;
  std::cout << "The comparision result (not equal): " << not_equal_result << std::endl << std::endl;

  std::cout << "Enter an integer and a double seperated by a space: ";
  std::cin >> num1 >> double1;
  equal_result = num1 == double1;
  not_equal_result = num1 != double1;
  std::cout << "The comparision result (equal): " << equal_result << std::endl;
  std::cout << "The comparision result (not equal): " << not_equal_result << std::endl << std::endl;

  return 0;
}
