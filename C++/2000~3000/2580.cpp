#include<iostream>
#include<vector>
using namespace std;

#define MAX 9

int table[MAX][MAX];

void print_sudoku()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << table[i][j];
			if (j != 8)
				cout << ' ';
		}
		cout << '\n';
	}
}

void sudoku(int row, int col)
{
	int used[9] = { 0 };
	vector<int> v;

	for (int i = 0; i < 9; i++) // 채우는 조건
	{
		if (table[row][i])        
			used[table[row][i] - 1] = 1;
		if (table[i][col])        
			used[table[i][col] - 1] = 1;
	}
	int sub_row = row / 3, sub_col = col / 3;	// square
	sub_row *= 3;  sub_col *= 3;	// square

	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++)
		{
			if (table[sub_row][sub_col + j])       
				used[table[sub_row][sub_col + j] - 1] = 1;
		}
		sub_row++;
	}
	for (int i = 0; i < 9; i++) 
	{
		if (!used[i])
			v.push_back(i + 1);
	}
	if (!v.size())
		return;

	int next_row = row, next_col = col;
	while (1)
	{
		if ((++next_col) == 9) 
		{
			next_row++;
			next_col = 0;
			if (next_row == 9) 
			{
				table[row][col] = v[0];
				print_sudoku();
				exit(0);
			}
		}
		if (next_row == 9) break;
		if (table[next_row][next_col] == 0) break;
	}

	for (int i = 0; i < v.size(); i++)	// 재귀를 위한 조건
	{
		table[row][col] = v[i];
		sudoku(next_row, next_col);
		table[row][col] = 0;
	}
}

int main()
{
	for(int i=0;i<9;i++)
		for (int j = 0; j < 9; j++)
		{
			cin >> table[i][j];
		}

	for (int i = 0; i<9; i++)
		for (int j = 0; j < 9; j++)
		{
			if (table[i][j] == 0)
				sudoku(i, j);
		}
}