/*

  *******IMPORTANT*******

  the passed array into a function can be change if you decide to change the values in the array.
  because the array which passed to a function will not copy the entire array. it will copy the first
  address of the array. 
  if you would not change the array inside another function just pass the array as a constant variable.
  since the passed array is an address, the function can't decide what is the size of the array. 
  so we have to pass the size as an argument.

  int array[] {10, 20, 30, 40, 50};

  std::cout << array << std::endl; => 0xb8613ff930 // this is the first address of the array in memory

  |--------|
  |   10   | => the location 0xb8613ff930 is here
  |--------|
  |   20   |
  |--------|
  |   30   |
  |--------|
  |   40   |
  |--------|
  |   50   |
  |--------|

*/

#include <iostream>

void print_arr(const int arr[], size_t size);
void change_arr(int arr[], size_t size, int new_value);

void print_arr(const int arr[], size_t size)
{
  for (size_t i {0}; i < size; i++)
    std::cout << arr[i] << " ";
  std::cout << std::endl;

  // arr[0] = 8000; // error => because arr is a constant
}

void change_arr(int arr[], size_t size, int new_value)
{
  for (size_t i {0}; i < size; i++)
    arr[i] = new_value;
}

int main()
{
  int array[] {10, 20, 30, 40, 50};

  std::cout << "The first location of array is: " << array << " " << &array[0] << std::endl;

  print_arr(array, 5);
  change_arr(array, 5, 100);
  print_arr(array, 5);

  return 0;
}
