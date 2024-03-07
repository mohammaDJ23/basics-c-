#include <iostream>
#include <vector>
#include <string>

void swap(int *const a, int *const b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void double_data(int *const i)
{
  *i *= 2;
}

void display(const std::vector<std::string> *const v)
{
  for (auto str : *v)
    std::cout << str << " ";
  std::cout << std::endl;
}

void display(const int *array, int sentinel)
{
  while (*array != sentinel)
    std::cout << *array++ << " ";
  std::cout << std::endl;
}

int main()
{
  int x {100};
  int y {200};
  int *ptr {nullptr};

  std::cout << "x is: " << x << std::endl;
  std::cout << "y is: " << y << std::endl;
  swap(&x, &y);
  std::cout << "x after swapping is: " << x << std::endl;
  std::cout << "y after swapping is: " << y << std::endl;

  ptr = &y;
  double_data(ptr);
  std::cout << "ptr after doubling is: " << *ptr << std::endl << std::endl;

  std::vector<std::string> vec {"Jack", "Frank"};
  display(&vec);
  std::cout << std::endl;

  int scores[] {10, 49, 50, -1};
  display(scores, -1);

  return 0;
}
