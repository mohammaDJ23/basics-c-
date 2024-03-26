/*

  weak_ptr

  - provides a non-owning "weak" reference

  -weak_ptr<T>
    - points to an object of type T on the heap
    - does not participate in owning relationship
    - always created from a shared_ptr
    - does not increment or decrement reference use count
    - pointer arithmetic not supported (++, --, etc)
    - used to prevent strong reference cycles which could prevent objects from being deleted

*/

#include <iostream>
#include <memory>

class B;

class A
{
private:
  std::shared_ptr<B> ptr;

public:
  A() { std::cout << "A constructor" << std::endl; }
  ~A() { std::cout << "A destructor" << std::endl; }

  void set_B(const std::shared_ptr<B> &ptr)
  {
    this->ptr = ptr;
  }
};

class B
{
private:
  // std::shared_ptr<A> ptr;
  std::weak_ptr<A> ptr; // this is the key

public:
  B() { std::cout << "B constructor" << std::endl; }
  ~B() { std::cout << "B destructor" << std::endl; }

  void set_A(const std::shared_ptr<A> &ptr)
  {
    this->ptr = ptr;
  }
};

class D;

class C
{
private:
  std::shared_ptr<D> ptr;

public:
  C() { std::cout << "C constructor" << std::endl; }
  ~C() { std::cout << "C destructor" << std::endl; }

  void set_D(const std::shared_ptr<D> &ptr)
  {
    this->ptr = ptr;
  }
};

class E;

class D
{
private:
  std::shared_ptr<E> ptr;

public:
  D() { std::cout << "D constructor" << std::endl; }
  ~D() { std::cout << "D destructor" << std::endl; }

  void set_E(const std::shared_ptr<E> &ptr)
  {
    this->ptr = ptr;
  }
};

class E
{
private:
  int num;

public:
  E() { std::cout << "E constructor" << std::endl; }
  ~E() { std::cout << "E destructor" << std::endl; }
};

int main()
{
  /*
  
    - example:
      the below example has this diagram.
      
      - A refers to B
      - B refers to A
      - Shared strong ownership prevents heap deallocation.

      stack                            heap
      |--------------|                  |--------------|
      | a |------|   |                  | A |------|   |
      |   |      |------------------------->|      |<---------|
      |   |      |   |                  |   |      |--------| |
      |   |------|   |                  |   |------|   |    |----->> shared_ptr<B>
      |              |                  |              |    | |
      | b |------|   |                  | B |------|   |    | |
      |   |      |   |                  |   |      |<-------| |--->> shared_ptr<A>
      |   |      |------------------------->|      |----------|
      |   |------|   |                  |   |------|   |
      |--------------|                  |--------------|

      - when the program goes out of the scope a and b will be destroy and
      A and B will not becuase they shared strong ownership with shared_ptr (A has ptr.use_count() => 1 and B has ptr.use_count() => 1).
      it means the A and B will not deallocate.
      for such an example we have to use weak_ptr becuase it does not have an strong ownership and does not count the connected pointers as said in the above explanation.

      - the solution is to use weak_ptr at one of the pointers in the classes.

      - see the example below
  
  */

  std::shared_ptr<A> a_ptr {std::make_shared<A>()};
  std::shared_ptr<B> b_ptr {std::make_shared<B>()};

  a_ptr->set_B(b_ptr);
  b_ptr->set_A(a_ptr);

  /*

    - example:

      stack                             heap
      |--------------|                  |--------------|
      | c |------|   |                  | C |------|   |
      |   |      |------------------------->|      |   |
      |   |      |   |                  |   |      |--------|
      |   |------|   |                  |   |------|   |    |
      |              |                  |              |    |
      | d |------|   |                  | D |------|   |    |
      |   |      |   |                  |   |      <--------|
      |   |      |------------------------->|      |--------|
      |   |------|   |                  |   |------|   |    |
      |              |                  |              |    |
      | e |------|   |                  | E |------|   |    |
      |   |      |------------------------->|      |<-------|
      |   |      |   |                  |   |      |   |
      |   |------|   |                  |   |------|   |
      |--------------|                  |--------------|
    
      - at this example there is no any circular reference so shared_ptr for deallocation work well 

      - see the example below

  */

  std::shared_ptr<C> c_ptr {std::make_shared<C>()};
  std::shared_ptr<D> d_ptr {std::make_shared<D>()};
  std::shared_ptr<E> e_ptr {std::make_shared<E>()};

  c_ptr->set_D(d_ptr);
  d_ptr->set_E(e_ptr);

  return 0;
}
