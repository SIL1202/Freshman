#include <iostream>
#include <cmath>
class Segment {
public:
	double x, y, x2, y2;
	double setX(double a, double b) {
		return pow((a - b), 2);
	}
	double setY(double a, double b) {
		return pow((a - b), 2);
	}
};
int main() {
	int n = 0;
	std::cin >> n;
	Segment point[n], pointfunc;
	for (int i = 0; i < n; i++)
		std::cin >> point[i].x >> point[i].y >> point[i].x2 >> point[i].y2;
	for (int i = 0; i < n; i++)
		std::cout << sqrt(pointfunc.setX(point[i].x, point[i].x2) + pointfunc.setY(point[i].y, point[i].y2)) << std::endl;
	return 0;
}
