#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
#define MAX 102

int n, m;
vector<int> graph[MAX];
bool check[MAX];
int cnt = 0;

void bfs()
{
	queue<int> q;
	q.push(1);
	check[1] = true;

	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		for (int i = 0; i < graph[temp].size(); i++)
		{
			int new_temp = graph[temp][i];
			if (check[new_temp] == false)
			{
				q.push(new_temp);
				check[new_temp] = true;
				cnt++;
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int temp1, temp2;
		cin >> temp1 >> temp2;

		graph[temp1].push_back(temp2);
		graph[temp2].push_back(temp1);
	}
	for (int i = 1; i < n+1; i++)
		sort(graph[i].begin(), graph[i].end());
	bfs();
	cout << cnt;

}