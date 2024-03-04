/*

  c-style string stores in memory with an \0 sign which is null at the end of string:

  example:
  
    [] is a block in memory

    "Frank"

    [F][r][a][n][k][\0]

    strlen("Frank") => 5
    the type of 5 is size_t not an integer

*/

#include <iostream>
#include <cctype> // for character-based functions
#include <cstring> // for c-style string functions

int main()
{
  char first_name[20] {};
  char last_name[20] {};
  char full_name[50] {};
  char temp[50] {};

  std::cout << "Please enter your first name: ";
  std::cin >> first_name;

  std::cout << "Please enter your last name: ";
  std::cin >> last_name;

  std::cout << "Your first name " << first_name << " has " << strlen(first_name) << " characters." << std::endl;
  std::cout << "Your last name " << last_name << " has " << strlen(last_name) << " characters." << std::endl;

  strcpy(full_name, first_name);
  strcat(full_name, " ");
  strcat(full_name, last_name);

  std::cout << "Your full name is " << full_name << "." << std::endl;
 
  std::cout << "We are testing your full name by getline function" << std::endl << "Enter your name: ";
  std::cin.ignore();
  std::cin.getline(full_name, 50);
  std::cout << "Your full name is: " << full_name << "." << std::endl;

  strcpy(temp, full_name);

  if (strcmp(temp, full_name) == 0)
    std::cout << temp << " and " << full_name << " are equal" << "." << std::endl;
  else
    std::cout << temp << " and " << full_name << " are not equal" << "." << std::endl;

  for (size_t i {0}; i < strlen(full_name); i++)
    if (isalpha(full_name[i]))
      full_name[i] = toupper(full_name[i]);

  std::cout << "Your full name is: " << full_name << "." << std::endl;

  if (strcmp(temp, full_name) == 0)
    std::cout << temp << " and " << full_name << " are equal" << "." << std::endl;
  else
    std::cout << temp << " and " << full_name << " are not equal" << "." << std::endl;

  std::cout << "Result of comparing " << temp << " and " << full_name << " is " << strcmp(temp, full_name) << "." << std::endl;
  std::cout << "Result of comparing " << full_name << " and " << temp << " is " << strcmp(full_name, temp) << "." << std::endl;

  return 0;
}
