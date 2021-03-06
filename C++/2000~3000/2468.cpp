#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int MAX = 100;
int map[MAX][MAX];
int dfs_map[MAX][MAX];
bool visit[MAX][MAX];
int n;

struct dir
{
	int dx;
	int dy;
};

dir direction[4] = { {0,1},{-1,0},{0,-1},{1,0} };

void make_map(int depth)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (map[i][j] > depth)
				dfs_map[i][j] = map[i][j];
}
void dfs(int x, int y)
{
	if (!dfs_map[x][y] || visit[x][y])
		return;
	visit[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int newX = x + direction[i].dx;
		int newY = y + direction[i].dy;
		if (newX >= 0 && newX < n && newY >= 0 && newY < n)
				dfs(newX, newY);
	}
}

int main()
{
	cin >> n;

	int limit = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			limit = max(limit, map[i][j]);
		}
	
	int cnt = 1, ans1=1;
	while (cnt <= limit)
	{
		memset(dfs_map, 0, sizeof(dfs_map));
		memset(visit, false, sizeof(visit));
		make_map(cnt);
		
		int cmp = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (dfs_map[i][j] && !visit[i][j])
				{
					dfs(i, j);
					cmp++;
				}
			}
		}
		cout << cmp << endl;
		ans1 = max(ans1, cmp);
		cnt++;
	}
	cout << ans1;
}