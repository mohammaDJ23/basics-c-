/*

  pointer pitfalls:
    - Uninitialized pointer
      for example:
        int *ptr; // points to anywhere maybe an important data!
        *ptr = 100;

    - dangling pointer
      1. pointer that is pointing to relased memory.
        for example:
          2 pointers point to the same data
          1 pointer releases the data with delete
          the other pointer accesses the release data

      2. pointer that points to memory that is invalid.
        we saw this when we returned a pointer to a function local variable.

    - not checking if new failed
      1. if new fails an exception is thrown.
      2. we can use exception handling to catch exceptions.
      3. dereferencing a null pointer will cause your program to crash.

    - leaking memory
      1. forgetting to release allocated memory with delete.
      2. if you lose your pointer to the storage allocated on the heap you have no way to get to that storage again.
      3. the memory is orphaned or leaked.
      4. one of the most common pointer problems.

*/

#include <iostream>

int main()
{
  return 0;
}
