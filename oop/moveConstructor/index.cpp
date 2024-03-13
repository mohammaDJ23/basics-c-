/*

  What is a Move Constructor?  

  The copy constructors in C++ work with the l-value references and 
  copy semantics(copy semantics means copying the actual data of the object to another object rather than 
  making another object to point the already existing object in the heap). 
  While move constructors work on the r-value references and 
  move semantics(move semantics involves pointing to the already existing object in the memory).

  On declaring the new object and assigning it with the r-value, firstly a temporary object is created, and then 
  that temporary object is used to assign the values to the object. 
  Due to this the copy constructor is called several times and increases the overhead and 
  decreases the computational power of the code. 
  To avoid this overhead and make the code more efficient we use move constructors.

  Why Move Constructors are used?

  Move constructor moves the resources in the heap, i.e., unlike 
  copy constructors which copy the data of the existing object and 
  assigning it to the new object move constructor just makes the pointer of the declared object to 
  point to the data of temporary object and nulls out the pointer of the temporary objects. 
  Thus, move constructor prevents unnecessarily copying data in the memory.  

  Work of move constructor looks a bit like default member-wise copy constructor but in this case, 
  it nulls out the pointer of the temporary object preventing more than one object to point to same memory location.

  you have to consider if the don't provide the move constructor in the class for r-value,
  the class will use the copy constructor and this will affect the performance.

*/

#include <iostream>
#include <vector>

class Move
{
private:
  int *data;
public:
  void set_data_value(int d) { *data = d; }
  int get_data_value() { return *data; }

  // constructor
  Move(int d);

  // copy constructor
  Move(const Move &source);

  // move constructor
  // if you don't provide move constructor,
  // the class will use the copy constructor
  Move(Move &&source);

  // destructor
  ~Move();
};

Move::Move(int d)
{
  data = new int;
  *data = d;
  std::cout << "Constructor of address " << this << " created." << std::endl;
}

Move::Move(const Move &source)
  : Move{*source.data} 
{
  std::cout << "Copy constructor of address " << this << " created from " << &source << "." << std::endl;
}

Move::Move(Move &&source)
  : data{source.data}
{
  source.data = nullptr; // the important part is here to remove all thing in the source
  std::cout << "Move constructor of address " << this << " created from " << &source << "." << std::endl;
}

Move::~Move()
{
  if (data != nullptr)
    std::cout << "Destructor of address " << this << " called." << std::endl;
  else
    std::cout << "Destructor of an nullptr address called." << std::endl;
}

int main()
{
  std::vector<Move> vec;
  Move move1 {10};

  std::cout << std::endl;
  vec.push_back(move1); // this will copy becuase move1 is l-value
  std::cout << std::endl;
  vec.push_back(Move{20}); // this will move becuase Move{20} is r-value
  std::cout << std::endl;
  vec.push_back(Move{40}); // this will move becuase Move{40} is r-value
  std::cout << std::endl;
  vec.push_back(Move{60}); // this will move becuase Move{60} is r-value
  std::cout << std::endl;
  vec.push_back(Move{80}); // this will move becuase Move{80} is r-value
  std::cout << std::endl;

  for (size_t i {0}; i < vec.size(); i++)
    std::cout << &vec.at(i) << " ";
  std::cout << std::endl << std::endl;

  return 0;
}
