#include<iostream>

using namespace std;
int n, m;
char map[11][11];
struct dir
{
	int dx;
	int dy;
};
dir direction[4] = { {0,1},{1,0},{0,-1},{-1,0} };
int Uturn()
{
	int uturn = false;
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 'X')
				continue;

			int cnt = 0;
			for (int k = 0; k < 4; k++)
			{
				int newY = j + direction[k].dy;
				int newX = i + direction[k].dx;
				if (newX >= 0 && newX < n && newY >= 0 && newY < m)
					if (map[newX][newY] == '.')
						cnt++;
			}
			if(cnt <= 1)
			{ 
				uturn = true;
				break;
			}
		}
	return uturn ? 1 : 0;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	cout << Uturn() << endl;
}