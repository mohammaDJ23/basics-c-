#include <iostream>
#include <string>

int main()
{
  std::string s0;
  std::string s1 {"Apple"};
  std::string s2 {"Banana"};
  std::string s3 {"Kiwi"};
  std::string s4 {"apple"};
  std::string s5 {s1};
  std::string s6 {s1, 0, 3};
  std::string s7 (10, 'X');

  std::cout << "Initialization" << std::endl 
    << "------------------------------" << std::endl;

  std::cout << "s0 is " << s0 << std::endl;
  std::cout << "s1 is " << s1 << std::endl;
  std::cout << "s2 is " << s2 << std::endl;
  std::cout << "s3 is " << s3 << std::endl;
  std::cout << "s4 is " << s4 << std::endl;
  std::cout << "s5 is " << s5 << std::endl;
  std::cout << "s6 is " << s6 << std::endl;
  std::cout << "s7 is " << s7 << std::endl;

  std::cout << std::endl;

  std::cout << "Comparison" << std::endl 
    << "------------------------------" << std::endl;

  std::cout << std::boolalpha;

  std::cout << s1 << " == " << s5 << ": " << (s1 == s5) << std::endl;
  std::cout << s1 << " == " << s2 << ": " << (s1 == s2) << std::endl;
  std::cout << s1 << " != " << s2 << ": " << (s1 != s2) << std::endl;
  std::cout << s1 << " < " << s2 << ": " << (s1 < s2) << std::endl;
  std::cout << s2 << " > " << s1 << ": " << (s2 > s1) << std::endl;
  std::cout << s4 << " < " << s5 << ": " << (s4 < s5) << std::endl;
  std::cout << s1 << " == " << "Apple" << ": " << (s1 == "Apple") << std::endl;

  std::cout << std::endl;

  std::cout << "Assignment" << std::endl 
    << "------------------------------" << std::endl;

  s1 = "Watermelon";
  std::cout << "s1 is now: " << s1 << std::endl;

  s2 = s1;
  std::cout << "s2 is now: " << s2 << std::endl;

  s3 = "Frank";
  std::cout << "s3 is now: " << s3 << std::endl;

  s3[0] = 'C';
  std::cout << "s3 at 0 position is changing to C: " << s3 << std::endl;

  s3.at(0) = 'P';
  std::cout << "s3 at 0 position is changing to P: " << s3 << std::endl;
  
  std::cout << std::endl;

  std::cout << "Concatenation" << std::endl 
    << "------------------------------" << std::endl;

  s2 = "Banana";
  s3 = "Watermelon";
  s3 = s5 + " and " + s2 + " juice";
  std::cout << "s3 is now: " << s3 << std::endl;
  
  std::cout << std::endl;

  std::cout << "For loop" << std::endl 
    << "------------------------------" << std::endl;

  s1 = "Apple";

  for (size_t i {0}; i < s1.length(); i++)
    std::cout << s1.at(i);
  std::cout << std::endl;
  
  std::cout << std::endl;

  std::cout << "Range loop" << std::endl 
    << "------------------------------" << std::endl;

  s1 = "Apple";

  for (char c : s1)
    std::cout << c;
  std::cout << std::endl;
  
  std::cout << std::endl;

  std::cout << "Substring" << std::endl 
    << "------------------------------" << std::endl;

  s1 = "This is a test";

  std::cout << s1.substr(0, 4) << std::endl;
  std::cout << s1.substr(5, 2) << std::endl;
  std::cout << s1.substr(10, 4) << std::endl;
  std::cout << s1.substr(5) << std::endl;
  
  std::cout << std::endl;

  std::cout << "Erase" << std::endl 
    << "------------------------------" << std::endl;

  s1 = "This is a test";

  std::cout << s1.erase(0, 5) << std::endl;
  std::cout << "s1 is now: " << s1 << std::endl;
  
  std::cout << std::endl;

  std::cout << "getline" << std::endl 
    << "------------------------------" << std::endl;

  std::string full_name {};

  std::cout << "Enter your full name: ";
  std::getline(std::cin, full_name);

  std::cout << "your full name is: " << full_name << std::endl;
  
  std::cout << std::endl;

  std::cout << "find" << std::endl 
    << "------------------------------" << std::endl;

  s1 = "The secret word in Boo";
  std::string word {};

  std::cout << "Enter a word to find the index: ";
  std::cin >> word;

  size_t position {s1.find(word)};

  if (position != std::string::npos)
    std::cout << "The position is: " << position << std::endl;
  else
    std::cout << "The word is not found.";
  
  std::cout << std::endl;

  return 0;
}
