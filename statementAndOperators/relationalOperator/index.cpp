/*

  two example of <=> three-way comprasion
  this means:
  A <=> B:
  A < B, A = B, or A > B



  example one:

  #include <compare>
  #include <iostream>
  using namespace std;
 
  int main()
  {
    int x = 10;
    int y = 20;

    // saving the result of 3 way comparison operator
    auto res = x <=> y;

    // executing statements based on the above comparison
    if (res < 0)
      cout << "Less";
    else if (res > 0)
      cout << "Greater";
    else if (res == 0)
      cout << "Same";
    else
      cout << "Unordered";
    
    return 0;
  }



  example two:

  #include <bits/stdc++.h>
  using namespace std;
 
  // Driver Code
  int main()
  {
    // Given vectors
    vector<int> v1{ 3, 6, 9 };
    vector<int> v2{ 3, 6, 9 };

    auto ans2 = v1 <=> v2;

    // If ans is less than zero
    if (ans2 < 0) {
      cout << "v1 < v2" << endl;
    }

    // If ans is equal to zero
    else if (ans2 == 0) {
      cout << "v1 == v2" << endl;
    }

    // If ans is greater than zero
    else if (ans2 > 0) {
      cout << "v1 > v2" << endl;
    }

    return 0;
  }

*/

#include <iostream>

int main()
{
  int num1 {};
  int num2 {};

  std::cout << std::boolalpha;
  std::cout << "Enter two number seporated by an space: ";
  std::cin >> num1 >> num2;

  std::cout << num1 << " > " << num2 << ": " << (num1 > num2) << std::endl;
  std::cout << num1 << " < " << num2 << ": " << (num1 < num2) << std::endl;
  std::cout << num1 << " == " << num2 << ": " << (num1 == num2) << std::endl;
  std::cout << num1 << " >= " << num2 << ": " << (num1 >= num2) << std::endl;
  std::cout << num1 << " <= " << num2 << ": " << (num1 <= num2) << std::endl;

  // the <=> will thorw an error
  // std::cout << num1 << " <=> " << num2 << ": " << (num1 <=> num2) << std::endl;

  return 0;
}
