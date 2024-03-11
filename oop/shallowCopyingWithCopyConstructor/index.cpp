/*

  *******IMPORTANT*******

  imagin you have a class which has a pointer as an private property.
  inside the constructor you initiate a dynamic allocation, for example an int pointer.
  
  then inside the destructor you free the allocated memory with delete keyword.
  so at this point, you have a pointer which points to an integer which allocated in heap with some value.

  imagin you copy the object by creating a new object using the source, or passing as an argument.
  here you will copy the all properties and also the pointer itself not what is pointing to.

  then when the destructer of the copied object called, the allocated memory will be released.

  and then the source object can not release the invalid memory becuase it has been released in the copied object (means the allocated value by pointer will remove).

  this story called shallow copy, becuase the pointer will be copied not what is pointing to.
  becuase you are using the same allocated memory in all the created class and when one of them changes the
  data which is pointing to at the class or somewhere else, the pointed data will change.
  at the next section we use deep copy to prevent this behavior.

  see the example below to understand what is going on.

  at the line 78 there is no 100 value in the allocated memory but the address exist. so we get a garbage data.

  and also at this example when program in main reaches to the end the destructor of obj2 and obj1 will call
  and both of them reaches to the invalid memory, means there is no 100 exist in there. a garbage data exist.

  but if you enable the line 87 the value of the address will be 1000.
  so at the destructor of obj2 and obj1, 1000 exists.

*/

#include <iostream>

class Shallow
{
private:
  int *data;
public:
  void set_data_value(int d) { *data = d; }
  int get_data_value() { return *data; }

  // constructor
  Shallow(int d);

  // copy constructor
  Shallow(const Shallow &source);

  // destructor
  ~Shallow();
};

Shallow::Shallow(int d)
{
  data = new int;
  *data = d;
  std::cout << "Constructor called. also the memory allocated at address " << data << "." << std::endl;
}

Shallow::Shallow(const Shallow &source)
  : data{source.data}
{
  std::cout << "Copy constructor is called." << std::endl;
}

Shallow::~Shallow()
{
  std::cout << "Destructor called and trying to release " << data << " address." << std::endl;
  delete data;
  std::cout << "data has been released at " << data << "." << std::endl;
}

void display_shallow(Shallow s)
{
  std::cout << s.get_data_value() << std::endl;
}

int main()
{
  Shallow obj1 {100};
  display_shallow(obj1);

  std::cout << "Value after releasing " << obj1.get_data_value() << std::endl;

  Shallow obj2 {obj1};

  // obj2.set_data_value(1000);

  return 0;
}
