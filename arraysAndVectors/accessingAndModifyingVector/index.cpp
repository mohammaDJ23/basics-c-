/*

  std::vector <int> scores (3);

  cout << scores[10]; // no bounce checking, the array syntax will not throw an array.
  cout << scores.at(10); // throw an error, always use this one.

  // modifying the scores

  cin >> scores[0];
  cin >> scores.at(0);

  scores[0] = 1;
  scores.at(0) = 2;

*/

/*

  std::vector <char> vowles; // empty
  std::vector <char> vowles (5); // the size is 5 and all values are 0

  std::vector <int> scores; // empty
  std::vector <int> scores (5); // the size is 5 and all values are 0
  std::vector <int> scores (5, 100); // the size is 5 and all values are 100

*/

#include <iostream>
#include <vector>

int main()
{
  std::vector <char> vowles {'a', 'e', 'o', 'i', 'u'};

  std::cout << "The value of the index of 0 with array syntax is: " << vowles[0] << std::endl;
  std::cout << "The value of the index of 3 with array syntax is: " << vowles[3] << std::endl;

  std::vector <int> scores {1, 2, 3};

  std::cout << "The value of the index of 0 with vector syntax is: " << scores.at(0) << std::endl;
  std::cout << "The value of the index of 1 with vector syntax is: " << scores.at(1) << std::endl;
  std::cout << "The value of the index of 2 with vector syntax is: " << scores.at(2) << std::endl;
  std::cout << "There are " << scores.size() << " scores in the vector." << std::endl;

  std::cout << "Enter three numbers to update the scores: ";
  std::cin >> scores.at(0);
  std::cin >> scores.at(1);
  std::cin >> scores.at(2);
  std::cout << "Updated results." << std::endl;
  std::cout << "The value of the index of 0 with vector syntax is: " << scores.at(0) << std::endl;
  std::cout << "The value of the index of 1 with vector syntax is: " << scores.at(1) << std::endl;
  std::cout << "The value of the index of 2 with vector syntax is: " << scores.at(2) << std::endl;

  int new_score {0};
  std::cout << "Enter a number to add to the vector: ";
  std::cin >> new_score;
  scores.push_back(new_score);

  std::cout << "Enter one more number to add to the vector: ";
  std::cin >> new_score;
  scores.push_back(new_score);

  std::cout << "The value of the index of 0 with vector syntax is: " << scores.at(0) << std::endl;
  std::cout << "The value of the index of 1 with vector syntax is: " << scores.at(1) << std::endl;
  std::cout << "The value of the index of 2 with vector syntax is: " << scores.at(2) << std::endl;
  std::cout << "The value of the index of 2 with vector syntax is: " << scores.at(3) << std::endl;
  std::cout << "The value of the index of 2 with vector syntax is: " << scores.at(4) << std::endl;
  std::cout << "There are " << scores.size() << " scores in the vector." << std::endl;

  std::cout << "This should cause a wrong result of index 9: " << scores[9] << std::endl;
  // std::cout << "This should cause an exception!!" << scores.at(9) << std::endl;

  std::vector <std::vector<int>> movie_ratings {
    {1, 2, 3, 4},
    {1, 2, 3, 4},
    {1, 2, 3, 4},
  };
  std::cout << "The rating of a movie is: " << movie_ratings.at(1).at(2) << std::endl;

  return 0;
}
