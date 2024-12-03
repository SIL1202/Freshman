#include <iostream>
#include <cmath>
using namespace std;
class Point
{
private:
  float x, y;

public:
  Point() : x(0), y(0) {}
  Point(float X, float Y) : x(X), y(Y)
  {
  }
  void printPoint()
  {
    cout << "(" << x << ", " << y << ")";
  }
  float getX() { return x; }
  float getY() { return y; }
  void setX(float X) { x = X; }
  void setY(float Y) { y = Y; }
  float getDistance(Point other)
  {
    float sum = pow(getX() - other.getX(), 2) + pow(getY() - other.getY(), 2);
    return sqrt(sum);
  }
};
class Segment
{
private:
  Point point1, point2;

public:
  Segment() : point1(Point()), point2(Point()) {}
  Segment(Point p1, Point p2) : point1(p1), point2(p2) {}
  float getLength() { return point1.getDistance(point2); }
};
