#include <iostream>
#include <string>
#include <vector>

int main()
{
  int score {100};
  int *score_ptr {&score};

  std::cout << "the score_ptr dereference value is: " << *score_ptr << std::endl;
  std::cout << "changing the score_ptr dereference value to 200..." << std::endl;
  *score_ptr = 200;
  std::cout << "the score_ptr dereference value is: " << *score_ptr << std::endl;
  std::cout << "the score value is: " << score << std::endl << std::endl;

  double high_temp {100.7};
  double low_temp {38.4};
  double *temp_ptr {&high_temp};

  std::cout << "the temp_ptr dereference value is: " << *temp_ptr << std::endl;
  temp_ptr = &low_temp;
  std::cout << "the temp_ptr dereference value is: " << *temp_ptr << std::endl << std::endl;

  std::string name {"Frank"};
  std::string *name_ptr {&name};

  std::cout << "the name_ptr dereference value is: " << *name_ptr << std::endl;
  name = "John";
  std::cout << "the name_ptr dereference value is: " << *name_ptr << std::endl;

  std::vector<std::string> name_vector {"Frank", "Moe", "Jack"};
  std::vector<std::string> *name_vector_ptr {&name_vector};

  std::cout << "The first name through the name_vector_ptr dereference value is: " << (*name_vector_ptr).at(0) << std::endl;
  std::cout << "The elements inside name_vector through the name_vector_ptr dereference value is: ";
  for (auto name : *name_vector_ptr)
    std::cout << name << " ";
  std::cout << std::endl;

  return 0;
}
