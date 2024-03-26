/*

  - sometimes when we destroy a smart pointer we need more than to just destory the object on the heap

  - these are special use-cases

  - c++ smart pointers allow you to provide custom deleters

  - lots of way to achieve this
    - functions => we have to initial with new keyword
    - lambda => we have to initial with new keyword
    - others...

  - example:
    custom deleters - function

    void my_deleter(Some_class *ptr) {
      delete ptr;
    }

    std::shared_ptr<Some_class> ptr {new Some_class{}, my_deleter};

  - example:
    custom deleters - lambda

    std::shared_ptr<Some_class> ptr {new Some_class{}, [] (Some_class *ptr) {
      std::cout << "Using my custom deleter" << std::endl;
      delete ptr;
    }};

*/

#include <iostream>
#include <memory>

class Test
{
private:
  int data;

public:
  Test() : data(0) { std::cout << "Test constrcutor" << std::endl; }
  ~Test() { std::cout << "Test destructor" << std::endl; }
};

void my_deleter(const Test *const ptr)
{
  std::cout << "Custom deleter called" << std::endl;
  delete ptr;
}

int main()
{
  {
    std::shared_ptr<Test> ptr {new Test(), my_deleter};
    std::cout << "Outting of the scope..." << std::endl;
  }

  {
    std::shared_ptr<Test> ptr {new Test(), 
      [] (const Test *const ptr) {
        std::cout << "Custom deleter called" << std::endl;
        delete ptr;
      }};
    std::cout << "Outting of the scope..." << std::endl;
  }

  return 0;
}
