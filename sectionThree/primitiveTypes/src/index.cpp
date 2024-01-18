/********************************************************
*  the size and precision of the types in c++ depends on the platform and compiler.
*  it could be find in climit library.
********************************************************/

/*

  Type Name             	Bytes              	Other Names	                                  Range of Values

  int                     4	                  signed	                                      -2,147,483,648 to 2,147,483,647
  unsigned int	          4	                  unsigned	                                    0 to 4,294,967,295
  __int8	                1	                  char	                                        -128 to 127
  unsigned __int8	        1	                  unsigned char	                                0 to 255
  __int16	                2	                  short, short int, signed short int	          -32,768 to 32,767
  unsigned __int16	      2	                  unsigned short, unsigned short int	          0 to 65,535
  __int32	                4	                  signed, signed int, int	                      -2,147,483,648 to 2,147,483,647
  unsigned __int32	      4	                  unsigned, unsigned int	                      0 to 4,294,967,295
  __int64	                8	                  long long, signed long long	                  -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
  unsigned __int64	      8	                  unsigned long long	                          0 to 18,446,744,073,709,551,615
  bool	                  1	                  none	                                        false or true
  char	                  1	                  none	                                        -128 to 127 by default, 0 to 255 when compiled by using /J
  signed char	            1	                  none	                                        -128 to 127
  unsigned char	          1	                  none	                                        0 to 255
  short	                  2	                  short int, signed short int	                  -32,768 to 32,767
  unsigned short	        2	                  unsigned short int	                          0 to 65,535
  long	                  4	                  long int, signed long int	                    -2,147,483,648 to 2,147,483,647
  unsigned long	          4	                  unsigned long int	                            0 to 4,294,967,295
  long long	              8	                  none (but equivalent to __int64)	            -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
  unsigned long long	    8	                  none (but equivalent to unsigned __int64)	    0 to 18,446,744,073,709,551,615
  enum	                  varies	            none
  float	                  4	                  none	                                        3.4E +/- 38 (7 digits)
  double	                8	                  none	                                        1.7E +/- 308 (15 digits)
  long double	            same as double	    none	                                        Same as double
  wchar_t	                2	                  __wchar_t	                                    0 to 65,535

*/

#include <iostream>
#include <iomanip>

int main()
{
  /********************************************************
  *  character type
  ********************************************************/

  std::cout << "*****************************" << " char type " << "*****************************" << std::endl;

  char middle_initial {'j'};
  std::cout << "My middle initial is " << middle_initial << "." << std::endl;

  /********************************************************
  *  integer type
  ********************************************************/

  std::cout << "*****************************" << " ingeter types " << "*****************************" << std::endl;

  unsigned short int exam_score {50};
  std::cout << "My exam score was " << exam_score << "." << std::endl;

  int counteries_represented {65};
  std::cout << "There were " << counteries_represented << " counteries represendted in my meeting." << std::endl;

  long int people_in_florida {20'610'000};
  std::cout << "There are about " << people_in_florida << " people in florida." << std::endl;

  long long int people_on_earth {7'600'000'000};
  std::cout << "There are about " << people_on_earth << " people on earth." << std::endl;

  unsigned long long int distance_to_alpha_centauri {9'161'000'000'000'000'000};
  std::cout << "The distance to alpha centauri is " << distance_to_alpha_centauri << " kilometers." << std::endl;

  /********************************************************
  *  floating point type
  ********************************************************/

  std::cout << "*****************************" << " floating types " << "*****************************" << std::endl;

  float payment {461.787};
  std::cout << "My payment is " << payment << "." << std::endl;

  long double long_number {2.7e120};
  std::cout << "The long number is " << long_number << std::endl;

  float car_payment {1.52313487};
  std::cout << std::setprecision(8);
  std::cout << "My car payment is " << car_payment << "." << std::endl;

  double box_payment {3.5231348727487777};
  std::cout << std::setprecision(16);
  std::cout << "My box payment is " << box_payment << "." << std::endl;

  long double computer_payment {3.523134872748777766666};
  std::cout << std::setprecision(20);
  std::cout << "My computer payment is " << computer_payment << "." << std::endl;

  /********************************************************
  *  bool type
  ********************************************************/

  std::cout << "*****************************" << " bool type " << "*****************************" << std::endl;

  bool is_game_over {false};
  std::cout << "The value of the game over is " << is_game_over << "." << std::endl;

  /********************************************************
  *  overflow examples
  ********************************************************/

  std::cout << "*****************************" << " overflow examples " << "*****************************" << std::endl;

  short int value_one {30000};
  short int value_two {1000};
  short int product {value_one * value_two}; // here the compiler will not catch the overflow but will show a warning.
  std::cout << "The product is " << product << "." << std::endl;

  long int numbers_of_stf = 7'600'000'000; // here the compiler will not catch the overflow but will show a warning.
  std::cout << "The numbers of stf are " << numbers_of_stf << "." << std::endl; 

  long int numbers_of_misl {7'600'000'000}; // here the compiler will catch the overflow.
  std::cout << "There numbers of misl are " << numbers_of_misl << "." << std::endl;

  return 0;
}
