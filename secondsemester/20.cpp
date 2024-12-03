#include <iostream>
#include <stack>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (int t = 0; t < n; t++)
	{
		int NumberOfRows, NumberOfCols;
		cin >> NumberOfRows >> NumberOfCols;
		int row_startingPoint, col_startingPoint;
		cin >> row_startingPoint >> col_startingPoint;
		int row_index, col_index;
		row_index = NumberOfRows + 1;
		col_index = NumberOfCols * 2 + 1;
		int matrix[row_index][col_index];
		for (int i = 0; i < row_index; i++)
		{
			for (int j = 0; j < col_index; j++)
			{
				matrix[i][j] = 0;
			}
		}
		for (int i = 0; i < row_index; i++)
		{
			for (int j = 0; j < col_index; j++)
			{
				if (i == 0 && j % 2 == 0)
				{
					matrix[i][j] = 0;
				}
				else if (j % 2 != 0)
				{
					matrix[i][j] = 2;
				}
				else if (j % 2 == 0)
				{
					matrix[i][j] = 1;
				}
			}
		}
		char direction;
		struct Point
		{
			int x, y;
		};
		stack<Point> store_steps_of_positions;
		while (!store_steps_of_positions.empty())
		{ // 清空stack直到他empty
			store_steps_of_positions.pop();
		}
		Point removed_cell_position;
		removed_cell_position.x = row_index - row_startingPoint;
		removed_cell_position.y = col_startingPoint * 2 - 1;
		store_steps_of_positions.push(removed_cell_position);
		for (int i = NumberOfRows * NumberOfCols - 1; i > 0; i--)
		{
			cin >> direction;
			if (direction == 'R')
			{
				removed_cell_position.y = removed_cell_position.y + 2;						// 加二是為了讓其他條件也滿足往右兩格
				matrix[removed_cell_position.x][removed_cell_position.y - 1] = 0; // 減一是為了消除 '|' 而不是 '_'
				store_steps_of_positions.push(removed_cell_position);
			}
			if (direction == 'U')
			{
				removed_cell_position.x--;
				matrix[removed_cell_position.x][removed_cell_position.y] = 0;
				store_steps_of_positions.push(removed_cell_position);
			}
			if (direction == 'D')
			{
				matrix[removed_cell_position.x][removed_cell_position.y] = 0;
				removed_cell_position.x++;
				store_steps_of_positions.push(removed_cell_position);
			}
			if (direction == 'L')
			{
				removed_cell_position.y = removed_cell_position.y - 2;						// 減二是為了讓其他條件也滿足往右兩格
				matrix[removed_cell_position.x][removed_cell_position.y + 1] = 0; // 加一是為了消除 '|' 而不是 '_'
				store_steps_of_positions.push(removed_cell_position);
			}
			if (direction == 'F')
			{
				int flip;
				cin >> flip;
				while (flip--)
				{
					store_steps_of_positions.pop();
				}
				i++; // flip不算走一次
				removed_cell_position = store_steps_of_positions.top();
			}
		}
		for (int i = 0; i < row_index; i++)
		{
			for (int j = 0; j < col_index; j++)
			{
				if (i == 0 && j == col_index - 1)
					continue; // 不能印出多餘的空白(第一行的最後一個)
				if (matrix[i][j] == 0)
				{
					cout << " ";
				}
				else if (matrix[i][j] == 1)
				{
					cout << "|";
				}
				else
					cout << "_";
			}
			cout << "\n";
		}
		cout << endl; // 每個測資之間要空一行
	}
	return 0;
}
