#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define MAX 5003
#define INF 987654321

int Friend[MAX][MAX];
int n, vertex;

void floyd_warshall()
{

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (i == j)
					continue;
				else if (Friend[i][k] && Friend[k][j])
				{
					if (Friend[i][j] == 0)
						Friend[i][j] = Friend[i][k] + Friend[k][j];
					else
						Friend[i][j] = min(Friend[i][j], Friend[i][k] + Friend[k][j]);
				}
}
int main()
{
	cin >> n >> vertex;

	for (int i = 0; i < vertex; i++)	//input
	{
		int temp1, temp2;
		cin >> temp1 >> temp2;
		Friend[temp1][temp2] = 1;
		Friend[temp2][temp1] = 1;
	}

	floyd_warshall();

	int MIN = INF;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int SUM = 0;
		for (int j = 1; j <= n; j++)
		{
			SUM += Friend[i][j];
		}
		if (SUM < MIN)
		{
			MIN = SUM;
			ans = i;
		}
	}
	cout << ans;
}