#include <iostream>
#include <cmath>
class Triangle {
public:
	double x, y, x2, y2, x3, y3;
	double ans;
	double setX(double a, double b) {
		return pow((a - b), 2);
	}
	double setY(double a, double b) {
		return pow((a - b), 2);
	}
	void sum(double a, double b, double c) {
		ans = a + b + c;
	}
	double perimeter();
};
double Triangle::perimeter() {
	return ans;
}
int main() {
	int n;
	double a;
	double b;
	double c;
	std::cin >> n;
	Triangle point[n], pointfunc;
	for (int i = 0; i < n; i++)
		std::cin >> point[i].x >> point[i].y >> point[i].x2 >> point[i].y2 >> point[i].x3 >> point[i].y3;
	for (int i = 0; i < n; i++) {
		a = sqrt(pointfunc.setX(point[i].x, point[i].x2) + pointfunc.setY(point[i].y, point[i].y2));
		b = sqrt(pointfunc.setX(point[i].x2, point[i].x3) + pointfunc.setY(point[i].y2, point[i].y3));
		c = sqrt(pointfunc.setX(point[i].x, point[i].x3) + pointfunc.setY(point[i].y, point[i].y3));
		point[i].sum(a, b, c);
	}
	for (int i = 0; i < n; i++)
		std::cout << point[i].perimeter() << std::endl;
	return 0;
}