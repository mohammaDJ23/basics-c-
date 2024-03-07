/*

  ******IMPORTANT******

  - do not return a pointer or variable address created in a function
    becuase it will store in stack. once the function finished, all variable will gone.
    for example:

    int *my_fn()
    {
      int num {10};
      int *ptr {&num};
      return ptr;
    }

    int *my_fn()
    {
      int num {10};
      return &num;
    }

    if you want to create a pointer inside a function, use the heap memory (dynamic memory allocation)
    and remember after you're done with the pointer, relase the pointer inside the parent function
    as you are returning the pointer to a parent function.

    if you want to return a pointer from a function,
      1 - pass a pointer created in the parent function to a function parameter and then return the pointer. exmaple 1
      2 - create a dynamic memory allocation inside a function
        then return it as a pointer then deallocate the pointer in the parent. example 2

*/

#include <iostream>

int *find_largest(int *x, int *y)
{
  if (*x > *y)
    return x;
  else
    return y;
}

int *create_arr(const size_t size, const int initial_val = 0)
{
  int *new_storage {nullptr};
  new_storage = new int[size];

  for (size_t i {0}; i < size; i++)
    *(new_storage + i) = initial_val;

  return new_storage;
}

void display(const int *const arr, size_t size)
{
  for (size_t i {0}; i < size; i++)
    std::cout << *(arr + i) << " ";
  std::cout << std::endl;
}

int main()
{
  // example 1

  int num1 {10};
  int num2 {20};
  int *num_ptr {nullptr};

  num_ptr = find_largest(&num1, &num2);

  std::cout << "larget num address is: " << &num_ptr << std::endl;

  // example 2

  size_t size {};
  int initial_val {};
  int *arr_ptr {nullptr};

  std::cout << "Enter the size of the array: ";
  std::cin >> size;
  std::cout << "Enter the inital values of the array: ";
  std::cin >> initial_val;

  arr_ptr = create_arr(size, initial_val);
  display(arr_ptr, size);

  delete [] arr_ptr;

  return 0;
}
