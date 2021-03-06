#include<iostream>
#include<cstring>
#include<queue>

#define MAX 300
using namespace std;

int l;
bool map[MAX][MAX];

struct dir
{
	int dx;
	int dy;
};
dir direction[8] = { {-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2} };

pair<int, int> source, destination;

void bfs(int a, int b)
{
	queue<pair<pair<int, int>, int >> q;	// x, y, cnt
	q.push(make_pair(make_pair(a, b), 0));
	map[a][b] = true;

	while (!q.empty())
	{
		int newX = q.front().first.first;
		int newY = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		
		if (newX == destination.first && newY == destination.second)
		{
			cout << cnt << endl;
			return;
		}
		for (int i = 0; i < 8; i++)
		{
			int nx = newX + direction[i].dx;
			int ny = newY + direction[i].dy;

			if (nx >= 0 && ny >= 0 && nx < l && ny < l)	// map 안에 있는가?
			{
				if (map[nx][ny] == 0)	// 안들렸나?
				{
					map[nx][ny] = true;
					q.push(make_pair(make_pair(nx, ny), cnt + 1));
				}
			}
		}
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		memset(map, 0, sizeof(map));
		cin >> l;
		cin >> source.first >> source.second;
		cin >> destination.first >> destination.second;

		bfs(source.first, source.second);
	}
}