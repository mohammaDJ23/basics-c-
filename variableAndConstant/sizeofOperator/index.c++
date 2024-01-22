#include <iostream>
#include <climits>

int main()
{
  std::cout << "The sizeof information." << std::endl;
  std::cout << "****************************************" << std::endl;

  std::cout << "The sizeof char is " << sizeof(char) << " bytes." << std::endl;
  std::cout << "The sizeof short int is " << sizeof(short int) << " bytes." << std::endl;
  std::cout << "The sizeof int is " << sizeof(int) << " bytes." << std::endl;
  std::cout << "The sizeof unsigned short int is " << sizeof(unsigned short int) << " bytes." << std::endl;
  std::cout << "The sizeof unsigned int is " << sizeof(unsigned int) << " bytes." << std::endl;
  std::cout << "The sizeof long int is " << sizeof(long int) << " bytes." << std::endl;
  std::cout << "The sizeof unsigned long int is " << sizeof(unsigned long int) << " bytes." << std::endl;
  std::cout << "The sizeof long long int is " << sizeof(long long int) << " bytes." << std::endl;
  std::cout << "The sizeof unsigned long long int is " << sizeof(unsigned long long int) << " bytes." << std::endl;

  std::cout << "****************************************" << std::endl;

  std::cout << "The sizeof float is " << sizeof(float) << " bytes." << std::endl;
  std::cout << "The sizeof double is " << sizeof(double) << " bytes." << std::endl;
  std::cout << "The sizeof long double is " << sizeof(long double) << " bytes." << std::endl;

  std::cout << "****************************************" << std::endl;

  std::cout << "Minimum values:" << std::endl;
  std::cout << "char " << CHAR_MIN << std::endl;
  std::cout << "short int " << SHRT_MIN << std::endl;
  std::cout << "int " << INT_MIN << std::endl;
  std::cout << "long int " << LONG_MIN << std::endl;
  std::cout << "long long int " << LLONG_MIN << std::endl;

  std::cout << "****************************************" << std::endl;

  std::cout << "Maximum values:" << std::endl;
  std::cout << "char " << CHAR_MAX << std::endl;
  std::cout << "short int " << SHRT_MAX << std::endl;
  std::cout << "int " << INT_MAX << std::endl;
  std::cout << "long int " << LONG_MAX << std::endl;
  std::cout << "long long int " << LLONG_MAX << std::endl;

  std::cout << "****************************************" << std::endl;

  std::cout << "The sizeof the variables:" << std::endl;

  int age {45};
  std::cout << "The sizeof age is " << sizeof(age) << " bytes." << std::endl;
  std::cout << "The sizeof age is " << sizeof age << " bytes." << std::endl;

  double wage {45.23};
  std::cout << "The sizeof wage is " << sizeof(wage) << " bytes." << std::endl;
  std::cout << "The sizeof wage is " << sizeof wage << " bytes." << std::endl;

  return 0;
}
