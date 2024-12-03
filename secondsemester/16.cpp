#include<iostream>
#include<string>
#include <cctype>
#include<algorithm>
using namespace std;
class Anagram {
public:
	string line;
	string afterconvert;
	Anagram(string other)
	{
		line = other;
		convert(line);
	}
	void convert(string n)
	{
		for (char c : n) {
			c = tolower(c);
			if (c >= 'a' && c <= 'z') {
				afterconvert.push_back(c);
			}
		}
		sort(afterconvert.begin(), afterconvert.end());
	}
	bool operator==(const Anagram& other) const
	{
		return afterconvert == other.afterconvert;
	}
};
int main() {
	string buf;
	getline(cin, buf);
	Anagram a1(buf);
	getline(cin, buf);
	Anagram a2(buf);
	cout << (a1 == a2) << endl;
	cout << (a2 == a1) << endl;
	return 0;
}