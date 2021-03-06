#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct dir
{
	int dx;
	int dy;
};
dir direction[4] = { { 0, 1 },{ -1, 0 },{ 0, -1 },{ 1, 0 } };

int n, m;
int result;
int map[10][10], temp_map[10][10];
vector<pair<int, int>> camera;
vector<int> angle;
bool visited[10][10][4];

void copy()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{ 
			temp_map[i][j] = map[i][j];
		}
}

int safety()
{
	int result = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (temp_map[i][j] == 0)
					result++;
	return result;
}
void dfs(int cnt)
{
	if (cnt == camera.size())
	{
		for (int i = 0; i < angle.size(); i++)
		{
			int x = camera[i].first;
			int y = camera[i].second;

			for (int j = 0; j < 4; j++)
			{
				if (visited[x][y][j])
				{
					int nextX = x + direction[(angle[i] + j) % 4].dx;
					int nextY = y + direction[(angle[i] + j) % 4].dy;

					while (1)
					{
						if (temp_map[nextX][nextY] == 6)
							break;
						if (!(0 <= nextX && nextX < n && 0 <= nextY && nextY < m))
							break;
						if (temp_map[nextX][nextY] == 0)
							temp_map[nextX][nextY] = -1;

						nextX += direction[(angle[i] + j) % 4].dx;
						nextY += direction[(angle[i] + j) % 4].dy;
					}
				}
			}
		}		
		result = min(result, safety());
		copy();
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		angle.push_back(i);
		dfs(cnt + 1);
		angle.pop_back();
	}
}
int main()
{
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];

			if (map[i][j] > 0 && map[i][j] < 6)
				camera.push_back({ i,j });

			switch (map[i][j])	// reset the first options
			{
			case 1:
				visited[i][j][0] = true;
				break;
			case 2:
				visited[i][j][0] = true;
				visited[i][j][2] = true;
				break;
			case 3:
				visited[i][j][0] = true;
				visited[i][j][1] = true;
				break;
			case 4:
				visited[i][j][0] = true;
				visited[i][j][1] = true;
				visited[i][j][2] = true;
				break;
			case 5:
				visited[i][j][0] = true;
				visited[i][j][1] = true;
				visited[i][j][2] = true;
				visited[i][j][3] = true;
				break;
			}
		}
	result = 987654321;
	copy();
	dfs(0);
	cout << result;
}