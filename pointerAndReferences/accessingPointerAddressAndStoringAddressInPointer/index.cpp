/*

  ********IMPORTANT********

  - a pointer must be initialize with nullptr.

  - a pointer with any type has the same sizeof.
    for example:
      int ptr1 {nullptr}; => for example 4 bytes or 8
      long long int ptr1 {nullptr}; => for example 4 bytes or 8

  - a pointer just contains an address of a variable.

  - the pointer value and address of a variable which points to a pointer are the same.

  - if you don't initialize a pointer, the pointer points to somewhere that should not points to.

*/

#include <iostream>
#include <string>
#include <vector>

int main()
{
  int num {10};
  
  std::cout << "Variable information" << std::endl;
  std::cout << "----------------------------------" << std::endl;
  std::cout << "The value of num is: " << num << std::endl;
  std::cout << "The sizeof of num is: " << sizeof(num) << std::endl;
  std::cout << "The address of num is: " << &num << std::endl << std::endl;

  int *ptr;
  
  std::cout << "Pointer information without initialization" << std::endl;
  std::cout << "--------------------------------------------------------" << std::endl;
  std::cout << "The value of ptr is: " << ptr << std::endl;
  std::cout << "The sizeof of ptr is: " << sizeof(ptr) << std::endl;
  std::cout << "The address of ptr is: " << &ptr << std::endl;
  std::cout << "assigning ptr to nullptr..." << std::endl;
  ptr = nullptr;
  std::cout << "The value of ptr is: " << ptr << std::endl << std::endl;

  int *ptr1 {nullptr};
  double *ptr2 {nullptr};
  unsigned long long int *ptr3 {nullptr};
  std::string *ptr4 {nullptr};
  std::vector<std::string> *ptr5 {nullptr};

  std::cout << "Pointers informantion with initialization" << std::endl;
  std::cout << "--------------------------------------------------------" << std::endl;
  std::cout << "The sizeof of ptr1 is: " << sizeof(ptr1) << std::endl;
  std::cout << "The sizeof of ptr2 is: " << sizeof(ptr2) << std::endl;
  std::cout << "The sizeof of ptr3 is: " << sizeof(ptr3) << std::endl;
  std::cout << "The sizeof of ptr4 is: " << sizeof(ptr4) << std::endl;
  std::cout << "The sizeof of ptr5 is: " << sizeof(ptr5) << std::endl << std::endl;

  int score {10};
  double high_temp {100.7};

  int *score_ptr {nullptr};

  score_ptr = &score;

  std::cout << "example" << std::endl;
  std::cout << "---------------------" << std::endl;
  std::cout << "The value of score is: " << score << std::endl;
  std::cout << "The sizeof of score is: " << sizeof(score) << std::endl;
  std::cout << "The address of score is: " << &score << std::endl;
  std::cout << "The value of score_ptr is: " << score_ptr << std::endl;
  std::cout << "The sizeof of score_ptr is: " << sizeof(score_ptr) << std::endl;
  std::cout << "The address of score_ptr is: " << &score_ptr << std::endl;
  std::cout << "The value of score through the score_ptr is: " << *score_ptr << std::endl << std::endl;

  // score_ptr = &high_temp; => error becuase high_temp is not an int which is the pointer type.

  return 0;
}
