#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;
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
    cout << "(" << x << ", " << y << ")" << endl;
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
  Point getStartPoint() const { return point1; }
  Point getEndPoint() const { return point2; }
};

class Shape
{
public:
  Shape() : edgeCount(0) {}
  Shape(Segment *segments, int count) : edgeCount(count)
  {
    if (count > 10 || count < 3)
    {
      throw invalid_argument("Number of segments exceeds maximum limit");
    }
    for (int i = 0; i < count; ++i)
    {
      seg[i] = segments[i];
    }
    if (count > 1 && (seg[0].getStartPoint().getX() != seg[count - 1].getEndPoint().getX() || seg[0].getStartPoint().getY() != seg[count - 1].getEndPoint().getY()))
      throw invalid_argument("Cannot construct a close path.");
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

