#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string map[10];
char ans[10][10];
int R, C;
struct dir
{
	int dx;
	int dy;
};
dir direction[4] = { {0,1},{1,0},{0,-1},{-1,0} };

int main()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++)
			cin >> map[i];

	int MAX_x = 0, MIN_x = 10, MAX_y = 0, MIN_y = 10;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			int cnt = 0;
			for (int l = 0; l < 4; l++)
			{
				int newX = i+direction[l].dx;
				int newY = j+direction[l].dy;
				if (newX < R && newX >= 0 && newY < C && newY >= 0)
				{
					if(map[newX][newY] == '.')
						cnt++;
				}
				else 
					cnt++;
			}
			if (cnt >= 3)
				ans[i][j] = '.';
			else if (cnt < 3 && map[i][j] == 'X')
				ans[i][j] = 'X';
			else
				ans[i][j] = '.';

			if (ans[i][j] == 'X')
			{
				MIN_x = min(MIN_x, i);
				MAX_x = max(MAX_x, i);
				MIN_y = min(MIN_y, j);
				MAX_y = max(MAX_y, j);
			}
		}
	}
	for (int i = MIN_x; i <= MAX_x; i++)
	{
		for (int j = MIN_y; j <= MAX_y; j++)
			cout << ans[i][j];
		cout << '\n';	
	}
}