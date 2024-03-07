#include <iostream>

int main()
{
  /*

    can not be change the value of the variable pointing to
    but the address of pointer can change.
  
  */

  int high_temp1 {100};
  int low_temp2 {20};
  const int *ptr1 {&high_temp1};

  *ptr1 = 101; // error
  ptr1 = &low_temp2;

  /*

    can not be change the address of the pointer
    but the value of the pointer can change.
  
  */

  int high_temp3 {100};
  int low_temp4 {20};
  int *const ptr2 {&high_temp3};

  *ptr2 = 101;
  ptr2 = &low_temp2; // error

  /*

    can not be change the address of the pointer
    and also the value of the variable pointing to.
  
  */

  int high_temp4 {100};
  int low_temp5 {20};
  const int *const ptr3 {&high_temp4};

  *ptr3 = 101; // error
  ptr3 = &low_temp2; // error

  return 0;
}
