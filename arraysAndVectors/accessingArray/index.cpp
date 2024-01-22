/*

  array initialization:

  int elements [5]; // do not do this. always initialize the array. maybe in future the result in array is not expected.
  int elements [5] {0}; // means {0, 0, 0, 0, 0}
  int elements [5] {1, 2, 3, 4, 5};
  int elements [5] {1, 2}; // means {1, 2, 0, 0, 0}

*/

#include <iostream>

int main()
{
  char vowels [5] {'a', 'e', 'i', 'o', 'u'};

  std::cout << "The first vowel is: " << vowels[0] << std::endl;
  std::cout << "The last vowel is: " << vowels[4] << std::endl;

  // std::cin >> vowels[5]; // don't do this. out of bounds

  // change the first element
  std::cin >> vowels[0];
  std::cout << "The first vowel is: " << vowels[0] << std::endl;

  // this kind of the initialization get the wrong result.
  // so initialize with:
  int test_scores [5];

  std::cout << "The score at index 1 is: " << test_scores[0] << std::endl;
  std::cout << "The score at index 2 is: " << test_scores[1] << std::endl;
  std::cout << "The score at index 3 is: " << test_scores[2] << std::endl;
  std::cout << "The score at index 4 is: " << test_scores[3] << std::endl;
  std::cout << "The score at index 5 is: " << test_scores[4] << std::endl;

  std::cin >> test_scores[0];
  std::cin >> test_scores[1];
  std::cin >> test_scores[2];
  std::cin >> test_scores[3];
  std::cin >> test_scores[4];

  std::cout << "The score at index 1 is: " << test_scores[0] << std::endl;
  std::cout << "The score at index 2 is: " << test_scores[1] << std::endl;
  std::cout << "The score at index 3 is: " << test_scores[2] << std::endl;
  std::cout << "The score at index 4 is: " << test_scores[3] << std::endl;
  std::cout << "The score at index 5 is: " << test_scores[4] << std::endl;
  
  std::cout << "The value of test_scores is: " << test_scores << std::endl;

  return 0;
}
