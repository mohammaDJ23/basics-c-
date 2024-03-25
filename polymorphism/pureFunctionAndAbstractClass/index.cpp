/*

  the Shape, Open_shape, Close_shape classes can not be initiale,
  because they are not overridden the virtual functions.
  so they are abstract classes.

*/

#include <iostream>
#include <vector>

// abstract class, becuase the funcitons are not overridden.
class Shape
{
protected:
  // attributes common to all shapes
  double area;

public:
  virtual void draw() = 0; // pure virtual function
  virtual void rotate() = 0; // pure virtual function

  void display_area() const
  {
    std::cout << this->area << std::endl;
  }

  Shape(const double area)
    : area(area) {}

  virtual ~Shape() {}
};

// abstract class, becuase the funcitons are not overridden.
class Open_shape: public Shape
{
public:
  Open_shape(const double area)
    : Shape(area) {}

  virtual ~Open_shape() {}
};

// abstract class, becuase the funcitons are not overridden.
class Close_shape: public Shape
{
public:
  Close_shape(const double area)
    : Shape(area) {}

  virtual ~Close_shape() {}
};

class Line: public Open_shape
{
public:
  virtual void draw() override
  {
    std::cout << "drawing a line" << std::endl;
  }

  virtual void rotate() override
  {
    std::cout << "rotating a line" << std::endl;
  }

  Line(const double area)
    : Open_shape(area) {}

  virtual ~Line() {}
};

class Circle: public Close_shape
{
public:
  virtual void draw() override
  {
    std::cout << "drawing a circle" << std::endl;
  }

  virtual void rotate() override
  {
    std::cout << "rotating a circle" << std::endl;
  }

  Circle(const double area)
    : Close_shape(area) {}

  virtual ~Circle() {}
};

class Square: public Close_shape
{
public:
  virtual void draw() override
  {
    std::cout << "drawing a square" << std::endl;
  }

  virtual void rotate() override
  {
    std::cout << "rotating a square" << std::endl;
  }

  Square(const double area)
    : Close_shape(area) {}

  virtual ~Square() {}
};

void screen_refresher(const std::vector<Shape*> &shapes)
{
  for (const auto &ptr: shapes) {
    ptr->draw();
    ptr->rotate();
    ptr->display_area();
  }
}

int main()
{
  // Shape s; // Error
  // Open_shape o; // Error
  // Close_shape c; // Error

  Shape *ptr1 = new Circle(2.0);
  Shape *ptr2 = new Line(0.4);
  Shape *ptr3 = new Square(4.5);

  std::vector<Shape*> vec {ptr1, ptr2, ptr3};
  screen_refresher(vec);

  delete ptr1;
  delete ptr2;
  delete ptr3;

  return 0;
}
