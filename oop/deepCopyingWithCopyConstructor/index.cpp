/*

  *******IMPORTANT*******

  at the shallow copy you saw just the pointer will be copy with the same address.
  but here at the deep copy we use another allocation memory and another address to apply our own change to specific object
  not the source.

  at the copy constructor we can create another allocated memory to prevent the shallow behavior.

  see the below example.

*/

#include <iostream>

class Deep
{
private:
  int *data;
public:
  void set_data_value(int d) { *data = d; }
  int get_data_value() { return *data; }

  // constructor
  Deep(int d);

  // copy constructor
  Deep(const Deep &source);

  // destructor
  ~Deep();
};

Deep::Deep(int d)
{
  data = new int;
  *data = d;
  std::cout << "Constructor called. also the memory allocated at address " << data << "." << std::endl;
}

Deep::Deep(const Deep &source)
  : Deep{*source.data}
{
  std::cout << "Copy constructor is called." << std::endl;
}

Deep::~Deep()
{
  std::cout << "Destructor called and trying to release " << data << " address." << std::endl;
  delete data;
  std::cout << "data has been released at " << data << "." << std::endl;
}

void display_deep(Deep s)
{
  std::cout << s.get_data_value() << std::endl;
}

int main()
{
  Deep obj1 {100};
  display_deep(obj1);

  std::cout << "the data value of obj1 is: " << obj1.get_data_value() << std::endl;

  Deep obj2 {obj1};

  obj2.set_data_value(1000);

  std::cout << "the data value of obj1 is still: " << obj1.get_data_value() << std::endl;
  std::cout << "the data value of obj2 is: " << obj2.get_data_value() << std::endl;

  return 0;
}
