#include <iostream>
#include <cmath>

class toll {
public:
	int tollcalculate(int x) {
		if (x <= 200)
			return round(x * 1.2);
		else
			return round(200 * 1.2 + (x - 200) * 1.2 * 0.75);
	}
};
int main() {
	toll func;
	int KM;
	std::cin >> KM;
	std::cout << func.tollcalculate(KM) << std::endl;
}