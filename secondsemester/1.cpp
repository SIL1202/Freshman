#include <iostream>
int main() {
	int n;
	float a, b;
	std::cin >> n;
	while (n--) {
		std::cin >> a >> b;
		std::cout << "(" << a << ", " << b << ")" << std::endl;
		if (n == 0) break;
	}
}