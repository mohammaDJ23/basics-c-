/*

  for this program i will be using US dollars and cents.

  write a program that asks the user to enter the following:
  an integer representing the number of cents

  you may assume that the number of cents entered is greater than or equal to zero

  the prgram sould then display how to pr ovide that change to the zero.

  is US:
    1 dollar is 100 cents
    1 quarter is 25 cents
    1 dime is 10 cents
    1 nickel is 5 cents
    1 penny is 1 cent

  here is a sample run:

  enter an amount in cents: 92

  you can provide this change as follows:
  dollars: 0
  quarters: 3
  dimes: 1
  nickels: 1
  pennies: 2

*/

#include <iostream>

int main()
{
  const int dollar_value {100};
  const int quarter_value {25};
  const int dime_value {10};
  const int nickel_value {5};
  const int penny_value {1};

  int charge_amount {0};

  std::cout << "Enter an amount in cents: ";
  std::cin >> charge_amount;

  int balance {0};

  int dollar {0};
  dollar = charge_amount / dollar_value;
  balance = charge_amount % dollar_value;

  int quarter {0};
  quarter = balance / quarter_value;
  balance %= quarter_value;

  int dime {0};
  dime = balance / dime_value;
  balance %= dime_value;

  int nickel {0};
  nickel = balance / nickel_value;
  balance %= nickel_value;

  int penny {0};
  penny = balance;

  std::cout << "dollars: " << dollar << std::endl;
  std::cout << "quarters: " << quarter << std::endl;
  std::cout << "dimes: " << dime << std::endl;
  std::cout << "nickels: " << nickel << std::endl;
  std::cout << "pennies: " << penny << std::endl;

  return 0;
}
