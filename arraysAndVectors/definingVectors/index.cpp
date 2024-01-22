#include <iostream>
#include <vector>

int main()
{
  // vectory with no value
  std::vector <char> chars;

  // vector with 5 length and zero elements: {0, 0, 0, 0, 0}
  std::vector <int> numbers (5);

  // vector with 6 length and 2 elements: {2, 2, 2, 2, 2, 2}
  std::vector <int> scores (6, 2);
  
  // vector with 5 length and elements: {1, 2, 3, 4, 5}
  std::vector <int> tests {1, 2, 3, 4, 5};
  
  // vector with 3 length and elements: {'a', 'b', 'c'}
  std::vector <char> tests {'a', 'b', 'c'};

  return 0;
}
