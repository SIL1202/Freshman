#include<iostream>
class Velocity {
public:
	double distance;
	double hour;
};
int main() {
	Velocity velocity;
	std::cin >> velocity.distance >> velocity.hour;
	std::cout << velocity.distance / velocity.hour << std::endl;
	return 0;
}