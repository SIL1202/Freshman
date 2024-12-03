#include<iostream>
#include<string>
using namespace std;
class Entity {
private:
	int integer;
public:
	Entity() 
	{
	}
	Entity(int n) {
		integer = n * 10;
	}
	int getNum() {
		return integer;
	}

};
class Integer {
private:
	Entity value[1000];
public:
	Integer() {

	}
	Integer(string n) {
		int i = 0;
		for (char ch : n) {
			value[i] = Entity((int)(ch - '0'));
		}
	}
	int getans() {
		return value[0].getNum();
	}
};
int main() {
	string in;
	cin >> in;
	Integer a(in);
	cout << a.getans() << endl;
	return 0;
}