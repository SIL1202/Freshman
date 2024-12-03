#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;
class Digit
{
private:
	int digit;

public:
	Digit() {}
	Digit(int d) : digit(d % 10) {}
	void setDigit(int d)
	{
		digit = d % 10;
	}
	int getDigit() const
	{
		return digit;
	}
};
class Integer
{
private:
	Digit value[1000];
	int j, num = 0;

public:
	Integer()
	{
		for (int i = 0; i < 1000; i++)
			value[i] = Digit(0);
	}
	Integer(string n)
	{
		j = 0;
		for (char ch : n)
		{
			if (ch <= '9' && ch >= '0')
			{
				value[j] = Digit(ch - '0');
				j++;
			}
			else
				break;
		}
	}

	void displayInBase(int base) const // con't modify the members in private
	{
		string digits = "0123456789ABCDEF";
		vector<int> ans, orginal, tmp;
		ans.clear();
		orginal.clear();
		tmp.clear();
		for (int i = 0; i < j; i++)
		{
			orginal.push_back(value[i].getDigit());
		}

		while (orginal.size() > 1 || orginal[orginal.size() - 1] != 0)
		{
			tmp.clear();
			int temp = 0;
			for (int i = 0; i < orginal.size(); i++)
			{
				temp *= 10;
				temp += orginal[i];
				if (tmp.size() == 0 && temp / base == 0)
					continue;
				tmp.push_back(temp / base);
				temp %= base;
			}
			ans.push_back(temp);
			orginal.clear();
			orginal.assign(tmp.begin(), tmp.end());
		}
		for (int i = ans.size() - 1; i >= 0; i--)
		{
			cout << digits[ans[i]];
		}
	}
};

int main()
{
	string in;
	int j;
	cin >> in;
	Integer i(in);
	for (j = 2; j <= 16; j++)
	{
		i.displayInBase(j);
		cout << endl;
	}
	return 0;
}
