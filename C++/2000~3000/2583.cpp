#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
const int MAX = 100;
typedef struct
{
	int dx, dy;
}dir;
dir direction[4] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1} };

int map[MAX][MAX];
bool check[MAX][MAX];

int n, m, k;
int cnt;
void MAP(int y, int x)
{
	check[y][x] = true;
	cnt++;

	for (int i = 0; i < 4; i++)
	{
		int newX = x + direction[i].dx;
		int newY = y + direction[i].dy;
		if (newX >= 0 && newX < n && newY >= 0 && newY < m)
			if (map[newY][newX] == 0 || !check[newY][newX])
				MAP(newY, newX);
	}
}
int main()
{
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int j = y1; j < y2; j++)
			for (int l = x1; l < x2; l++)
				map[j][l] = 1;
	}
	vector<int> ans;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (!check[i][j] && map[i][j] == 0)
			{
				cnt = 0;

				MAP(i, j);
				ans.push_back(cnt);
			}
	cout << ans.size() << endl;
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
}