#include<iostream>
#include<cstring>
#include<queue>

#define MAX 100
using namespace std;

int n;
bool visited[MAX][MAX];
char map[MAX][MAX];
int cnt=0, RG_cnt=0;

struct dir
{
	int dx;
	int dy;
};
dir direction[4] = { {1,0},{0,1},{-1,0},{0,-1} };

void bfs(int x, int y)
{
	queue<pair<int, int>> q;	// x,y	
	q.push(make_pair(x, y));
	visited[x][y] = true;

	while (!q.empty())
	{
		int newX = q.front().first;
		int newY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = newX + direction[i].dx;
			int ny = newY + direction[i].dy;

			if (nx >= 0 && ny >= 0 && nx < n && ny < n)	// map 안에 있는가?
			{
				if (visited[nx][ny] == false)	// 안들렸나?
				{
					if (map[newX][newY] == map[nx][ny])	// 움직이기 전과 같은가?
					{
						visited[nx][ny] = true;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
}
void RG_bfs(int x, int y)
{
	queue<pair<int, int>> q;	// x,y	
	q.push(make_pair(x, y));
	visited[x][y] = true;

	while (!q.empty())
	{
		int newX = q.front().first;
		int newY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = newX + direction[i].dx;
			int ny = newY + direction[i].dy;

			if (nx >= 0 && ny >= 0 && nx < n && ny < n)	// map 안에 있는가?
			{
				if (visited[nx][ny] == false)	// 안들렸나?
				{
					if (map[newX][newY] == map[nx][ny])
					{
						visited[nx][ny] = true;
						q.push(make_pair(nx, ny));
						continue;
					}
					else if ((map[newX][newY] == 'R' || map[newX][newY] == 'G') && (map[nx][ny] == 'R' || map[nx][ny] == 'G'))	// 움직이기 전과 같은가?
					{
						visited[nx][ny] = true;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	memset(visited, 0, sizeof(visited));
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] == false)
			{
				bfs(i, j);
				cnt++;
			}
		}
	memset(visited, 0, sizeof(visited));
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] == false)
			{
				RG_bfs(i, j);
				RG_cnt++;
			}
		}
	cout << cnt << ' ' << RG_cnt << endl;
}