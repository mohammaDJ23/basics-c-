#include <iostream>

int main()
{
  int scores[] {10, 20, 30};
  int *score_ptr {scores};

  std::cout << "accessing scores array by subscription by scores ( scores[0] )" << std::endl;
  std::cout << "--------------------------------------------------------------" << std::endl;
  std::cout << scores[0] << std::endl;
  std::cout << scores[1] << std::endl;
  std::cout << scores[2] << std::endl << std::endl;

  std::cout << "accessing scores array by offset with * sign by scores ( *(scores + 1) )" << std::endl;
  std::cout << "------------------------------------------------------------------------" << std::endl;
  std::cout << *scores << std::endl;
  std::cout << *(scores + 1) << std::endl;
  std::cout << *(scores + 2) << std::endl << std::endl;

  std::cout << "accessing scores array by subscription by score_ptr ( score_ptr[0] )" << std::endl;
  std::cout << "--------------------------------------------------------------------" << std::endl;
  std::cout << score_ptr[0] << std::endl;
  std::cout << score_ptr[1] << std::endl;
  std::cout << score_ptr[2] << std::endl << std::endl;

  std::cout << "accessing scores array by offset with * sign by score_ptr ( *(score_ptr + 1) )" << std::endl;
  std::cout << "------------------------------------------------------------------------------" << std::endl;
  std::cout << *score_ptr << std::endl;
  std::cout << *(score_ptr + 1) << std::endl;
  std::cout << *(score_ptr + 2) << std::endl << std::endl;

  return 0;
}
