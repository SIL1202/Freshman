#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Matrix
{
private:
	vector<vector<int>> matrix;
	int n = 0;

public:
	void scan()
	{
		cin >> n;
		matrix.resize(n, vector<int>(n));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> matrix[i][j];
			}
		}
	}

	void print()
	{
		if (n == 0)
		{
			cout << "No element in matrix can be printed.\n";
			return;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
		cout << "\n";
	}

	void right()
	{
		if (n == 0)
		{
			cout << "No element in matrix can be rotated.\n";
			return;
		}
		vector<vector<int>> temp;
		temp.resize(n, vector<int>(n));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				temp[i][j] = matrix[n - 1 - j][i];
			}
		}
		matrix = temp;
	}
	void left()
	{
		if (n == 0)
		{
			cout << "No element in matrix can be rotated.\n";
			return;
		}
		vector<vector<int>> temp;
		temp.resize(n, vector<int>(n));
		for (int i = 0; i < 3; i++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					temp[i][j] = matrix[n - 1 - j][i];
				}
			}
			matrix = temp;
		}
	}
};

int main()
{
	string instruction;
	Matrix func;
	while (true)
	{
		cin >> instruction;
		if (instruction == "stop")
			return 0;
		else if (instruction == "rotate")
		{
			cin >> instruction;
			if (instruction == "right")
				func.right();
			else if (instruction == "left")
				func.left();
			else
				cout << "unknown\n";
		}
		else if (instruction == "print")
			func.print();
		else if (instruction == "scan")
			func.scan();
		else
			cout << "unknown\n";
	}
	return 0;
}