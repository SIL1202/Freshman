#include <iostream>
#include <cmath>
#include <stdexcept>

class Point
{
private:
  float x;
  float y;

public:
  Point() : x(0), y(0) {}
  Point(float a, float b) : x(a), y(b) {}

  void printPoint()
  {
    std::cout << "(" << x << ", " << y << ")" << std::endl;
  }

  float getX()
  {
    return x;
  }

  void setX(float c)
  {
    x = c;
  }

  float getY()
  {
    return y;
  }

  void setY(float d)
  {
    y = d;
  }

  float getDistance(Point other)
  {
    float sum = pow(getX() - other.getX(), 2) + pow(getY() - other.getY(), 2);
    return sqrt(sum);
  }
};

class Segment
{
private:
  Point point1;
  Point point2;

public:
  Segment() {}
  Segment(Point p1, Point p2) : point1(p1), point2(p2) {}

  float getLength()
  {
    return point1.getDistance(point2);
  }

  Point getStartPoint() const
  {
    return point1;
  }

  Point getEndPoint() const
  {
    return point2;
  }
};

class Shape
{
public:
  Shape() : edgeCount(0) {}
  Shape(Segment *segments, int count) : edgeCount(count)
  {
    if (count > 10 || count < 3)
    {
      throw std::invalid_argument("Number of segments exceeds maximum limit or is less than 3");
    }
    for (int i = 0; i < count; ++i)
    {
      seg[i] = segments[i];
    }
    if (count > 1 && (seg[0].getStartPoint().getX() != seg[count - 1].getEndPoint().getX() || seg[0].getStartPoint().getY() != seg[count - 1].getEndPoint().getY()))
    {
      throw std::invalid_argument("Cannot construct a close path.");
    }
  }

  virtual float getArea() = 0;

  float getPerimeter()
  {
    float perimeter = 0.0;
    for (int i = 0; i < edgeCount; ++i)
    {
      perimeter += seg[i].getLength();
    }
    return perimeter;
  }

  Segment &getSeg(int index)
  {
    return seg[index];
  }

protected:
  Segment seg[10];
  int edgeCount;
};

class Rectangle : public Shape
{
public:
  Rectangle(Segment *segments)
  {
    float lengths[4];
    for (int i = 0; i < 4; ++i)
    {
      lengths[i] = segments[i].getLength();
    }
    if (lengths[0] != lengths[2] || lengths[1] != lengths[3])
    {
      throw std::invalid_argument("Given segments do not form a rectangle");
    }

    edgeCount = 4;
    for (int i = 0; i < 4; ++i)
    {
      seg[i] = segments[i];
    }
  }

  float getArea() override
  {
    float length = getSeg(0).getLength();
    float breadth = getSeg(1).getLength();
    return length * breadth;
  }
};

/*int main()
{
  Point p1(0, 0);
  Point p2(5, 0);
  Point p3(5, 3);
  Point p4(0, 3);
  Segment segment[] = {Segment(p1, p2), Segment(p2, p3), Segment(p3, p4), Segment(p4, p1)};

  try
  {
    Rectangle rectangle(segment);
    std::cout << "Area of rectangle: " << rectangle.getArea() << std::endl;
    std::cout << "Perimeter of rectangle: " << rectangle.getPerimeter() << std::endl;
  }
  catch (const std::invalid_argument &e)
  {
    std::cerr << "Error creating rectangle: " << e.what() << std::endl;
  }
  return 0;
}
*/
