#include <iostream>

class digits {
private:
	int a, b, c, d;
public:
	int four(int num) {//1250
		a = num % 10;    //0
		num = num / 10; //125
		b = num % 10; //5
		num = num / 10; //12
		c = num % 10; //2
		d = num / 10; //1
		if (a == 4 || b == 4 || c == 4 || d == 4)
			return 1;
		else
			return 0;
	}
};
int main() {
	int number;
	digits func;
	std::cin >> number;
	if (func.four(number) == 1)
		std::cout << "Yes";
	else
		std::cout << "No";
	return 0;
}