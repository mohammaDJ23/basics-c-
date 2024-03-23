/*

  class Base
  {
  public:
    int a{0.0};

  protected:
    int b{0.0};

  private:
    int c{0.0};
  };


  public Base means:
    Base:                 Derived:
      public: a             public: a
      protected: b          protected: b
      private: c            private: c => no access

  class Derived: public Base
  {};


  protected Base means:
    Base:                 Derived:
      public: a             protected: a
      protected: b          protected: b
      private: c            private: c => no access

  class Derived: protected Base
  {};


  private Base means:
    Base:                 Derived:
      public: a             private: a
      protected: b          private: b
      private: c            private: c => no access

  class Derived: private Base
  {};

*/

#include <iostream>

class Base
{
public:
  int a{0.0};

protected:
  int b{0.0};

private:
  int c{0.0};
};

class Derived: public Base
{};

int main()
{
  Base base;
  base.a = 100; // Ok
  base.b = 200; // Error
  base.c = 300; // Error

  Derived derived;
  derived.a = 100; // Ok
  derived.b = 200; // Error
  derived.c = 300; // Error

  return 0;
}
