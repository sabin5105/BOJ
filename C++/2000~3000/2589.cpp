#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

string map[50];
bool visited[50][50];
int cache[50][50];
int n, m;

struct dir
{
	int dx;
	int dy;
};
dir direction[4] = { {0,1},{1,0},{-1,0},{0,-1} };

int bfs(int x, int y)
{
	memset(cache, 0, sizeof(cache));

	int cnt = 0;
	queue<pair<int,int>> q;
	q.push(make_pair(x, y));
	cache[x][y] = 1;

	while (!q.empty())
	{
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int new_x = nx + direction[i].dx;
			int new_y = ny + direction[i].dy;

			cnt = max(cnt, cache[nx][ny]);

			if (new_x >= n || new_x < 0 || new_y >= m || new_y < 0)
				continue;
			if (cache[new_x][new_y] == 0 && map[new_x][new_y] == 'L')
			{
				q.push(make_pair(new_x, new_y));
				cache[new_x][new_y] = cache[nx][ny] + 1;
			}
		}
	}
	return cnt - 1;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> map[i];
	}

	int MAX = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 'L')
			{
				MAX = max(MAX, bfs(i,j));
			}
		}
	}
	cout << MAX;
}