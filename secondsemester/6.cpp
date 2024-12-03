#include<iostream>
class point {
private:
	float x, y;
public:
	point(point x, point y) : p1(x), p2(y) {}
	float getX() {
		return x;
	}
	float getY() {
		return y;
	}
};

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> p1.getX() >> p2.getY();
		std::cout << "(" << p1.getX() << ", " << p2.getY() << ")" << std::endl;
	}
	return 0;
}