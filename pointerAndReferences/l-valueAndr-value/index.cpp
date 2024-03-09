/*

  l-values:
    - values that have names and are addressable
    - modifiable if they are not constants

    int x {100}; // x is an l-value

    string name; // name is an l-value

    (100 + 2) = x; // (100 + 2) is not an l-value

    "Frank" = name; // "Frank" is not an l-value

    int x {100};
    int &ref = x // ref is reference to l-value;
    ref = 1000;

    int square(int &n)
    {
      return n * n;
    }
    int num {10};
    square(num); // OK
    square(5); // Error - can't reference r-value 5

  r-values:
    - not-addressalbe
    - not-assignable

    int x {100}; // 100 is an r-value

    int y = x + 200; // (x + 200) is an r-value

    string name;
    name = "Frank" // "Frank" is an r-value

    int max_num = max(20, 30); // max(20, 30) is an r-value

    int &ref = 100; // Error 100 is an r-value

*/

#include <iostream>

int main()
{
  return 0;
}
