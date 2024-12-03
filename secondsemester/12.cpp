#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const string num = "0123456789";
class Digit
{ // class Digit represent a digit in base 10
	int digit;

public:
	Digit(int d = 0) : digit(d % 10) {}
	void setDigit(int d) { digit = d % 10; }
	int getDigit() const { return digit; }
};
class Integer
{ // class Integer represent a integer
	Digit value[1000];
	bool sign = 0;
	int count = 0;

public:
	// default constructor will construct an Integer object with value 0.
	Integer()
	{
		for (int i = 0; i < 1000; i++)
		{
			value[i].setDigit(0);
		}
	}
	// construct an integer in base 10 using a string.
	// This constructor will convert the given string to integer if possible.
	// Otherwise it will convert the digit part in prefix of the given string.
	Integer(string n)
	{
		count = 0;
		reverse(n.begin(), n.end());
		for (char num : n)
		{
			if (num <= '9' && num >= '0')
			{
				value[count].setDigit(num - '0');
				count++;
			}
			else if (num == '-')
				sign = 1;
		}
	}
	// function addition will add up two integer and return a new Integer object as result.
	Integer addition(const Integer &b) const
	{
		string sum;
		int len = max(count, b.count);
		int carry = 0;
		for (int i = 0; i < len; i++)
		{
			int temp = value[i].getDigit() + b.value[i].getDigit() + carry;
			carry = 0;
			if (temp >= 10)
			{
				carry = 1;
				temp -= 10;
			}
			sum.push_back(num[temp]);
		}
		if (carry)
			sum.push_back(num[1]);
		reverse(sum.begin(), sum.end());
		return Integer(sum);
	}
	// function subtraction will minus b from current object and return a new Integer object as result.
	Integer subtraction(const Integer &b) const
	{
		string differ;
		int carry = 0;
		bool negative = 0;
		if (count < b.count)
			negative = 1;

		else if (count == b.count)
		{
			for (int i = count - 1; i >= 0; i--)
			{
				if (value[i].getDigit() > b.value[i].getDigit())
				{
					break;
				}
				else if (value[i].getDigit() < b.value[i].getDigit())
				{
					negative = 1;
					break;
				}
			}
		}

		int len = max(count, b.count);
		int temp = 0;
		for (int i = 0; i < len; i++)
		{
			if (negative)
			{
				temp = b.value[i].getDigit() - value[i].getDigit() - carry;
			}
			else
			{
				temp = value[i].getDigit() - b.value[i].getDigit() - carry;
			}
			carry = 0;
			if (temp < 0)
			{
				temp += 10;
				carry = 1;
			}
			differ.push_back(num[temp]);
		}
		if (negative)
			differ.push_back('-');
		reverse(differ.begin(), differ.end());
		return Integer(differ);
	}
	void display()
	{
		bool isZero = 1;
		if (sign)
			cout << "-";
		for (int i = count - 1; i >= 0; i--)
		{
			if (value[i].getDigit() != 0)
				isZero = 0;
			cout << " iszero = " << isZero << " ";
			if (value[i].getDigit() != 0 || isZero == 0 || i == 0)
				cout << num[value[i].getDigit()];
		}
	}
};

int main()
{
	string a, b;
	cin >> a >> b;
	Integer num1(a), num2(b);
	num1.addition(num2).display();
	cout << endl;
	num2.addition(num1).display();
	cout << endl;
	num1.subtraction(num2).display();
	cout << endl;
	num2.subtraction(num1).display();
	cout << endl;
}