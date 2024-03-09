#include <iostream>

void print(const int *const p, const size_t size)
{
  std::cout << "[ ";
  for (size_t i {0}; i < size; i++)
    std::cout << *(p + i) << " ";
  std::cout << "]";
  std::cout << std::endl;
}

int *apply_all(const int *const arr1, size_t size1, const int *const arr2, size_t size2)
{
  int *new_storage = new int[size1 * size2];

  for (size_t i {0}; i < size2; i++)
    for (size_t j {0}; j < size1; j++)
      *(new_storage + ((size1 * i) + j)) = *(arr2 + i) * *(arr1 + j);

  return new_storage;
}

int main()
{
  const int arr1_size {5};
  const int arr2_size {3};

  int arr1[] {1, 2, 3, 4, 5};
  int arr2[] {10, 20, 30};
  
  std::cout << "arr1 is: ";
  print(arr1, arr1_size);

  std::cout << "arr2 is: ";
  print(arr2, arr2_size);

  int *ptr {apply_all(arr1, arr1_size, arr2, arr2_size)};
  constexpr int ptr_size {arr1_size * arr2_size};

  std::cout << "ptr is: ";
  print(ptr, ptr_size);

  delete [] ptr;

  return 0;
}
