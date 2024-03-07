/*

  sometime we have a variable and use the variable address to store to the pointer then with pointer we can
  access to the variable address and value.

  but now we don't have any variable becuase of that we use pointer to create a variable.

  imagin we want to define a variable through the pointer.
  so we need some memory space to define that.
  we use heap memory to allocate such a variable definition through the pointer.

  we have to consider allocation and deallocation memory for any pointers
  otherwise we encouter memory leak if we did not release the allocated menory (deallocation). 
  the defined variable has no name. the only way to get the variable
  is the pointer if somehow we lose the pointer, we have memory leak.

  after we allocate the location of a variable to the pointer (with new keyword),
  we quickly have to initialize the variable through the pointer otherwise we see the garbage data.

  the pointer itself is store in stack.

*/

#include <iostream>

int main()
{
  int *int_ptr {nullptr};

  // allocating a memory space...
  // which will store an addres to the pointer
  int_ptr = new int;

  // here we defined a value for the variable
  // if use access to the value of the variable by pointer before this line you get garbage adta.
  *int_ptr = 100;
  std::cout << "a variable with address: " << int_ptr << " on heap has " << *int_ptr << " value." << std::endl;

  std::cout << "releasing the allocated memory for the variable..." << std::endl;
  // release the pointer
  delete int_ptr;
  std::cout << "released." << std::endl << std::endl;

  int size {};
  double *temp_ptr {nullptr};

  std::cout << "How many temps? ";
  std::cin >> size;

  // will define a variable with array of some size...
  temp_ptr = new double[size];

  // printing the first address of the array...
  std::cout << "the value of temp_ptr is: " << temp_ptr << std::endl;

  // releasing...
  delete [] temp_ptr;

  return 0;
}
