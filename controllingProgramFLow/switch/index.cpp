#include <iostream>

int main()
{
  enum Direction {left, right, up, down};
  Direction heading {left};

  switch (heading) {
    case left: {
      std::cout << "The direction is left." << std::endl;
      break;
    }

    case right: {
      std::cout << "The direction is right." << std::endl;
      break;
    }

    default: {
      std::cout << "The direction is up or down." << std::endl;
      break;
    }
  }

  return 0;
}
