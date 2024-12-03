#include <iostream>
class Segment {
public:
	int a, b, c, d;
	int True = 0;
	void trueOrfalse(int a, int b, int c, int d) {
		if (a < d && c < b)
			True = 1;
		else
			True = 0;
	}
	bool overlay();
};
bool Segment::overlay() {
	if (True==1)
		return 1;
	else
		return 0;
}
int main() {
	int a, b, c, d;
	a = b = c = d = 0;
	Segment func;
	std::cin >> a >> b >> c >> d;
	if (a > b) {
		int temp = a;
		a = b;
		b = temp;
	}
	if (c > d) {
		int temp = c;
		c = d;
		d = temp;
	}
	func.trueOrfalse(a, b, c, d);
	if (func.overlay())
		std::cout << "overlay" << std::endl;
	else 
		std::cout << "no overlay" << std::endl;
}