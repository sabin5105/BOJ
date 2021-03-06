#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
#define MAX 102

vector<int> v[MAX];
bool check[MAX];

int n,M;
int START, END;
int cnt[MAX];
int bfs()
{
	queue<int> q;
	q.push(START);
	check[START] = true;

	while (!q.empty())
	{
		int temp = q.front();
		q.pop();

		if (temp == END)
			return cnt[temp];

		for (int i = 0; i < v[temp].size(); i++)
		{
			if (check[v[temp][i]] == false)
			{
				q.push(v[temp][i]);
				check[v[temp][i]] = true;
				cnt[v[temp][i]] = cnt[temp] + 1;
			}
		}
	}
	return -1;
}
int main()
{
	cin >> n;
	cin >> START >> END >> M;
	for (int i = 0; i < M; i++)
	{
		int temp1 , temp2;
		cin >> temp1 >> temp2;
		v[temp1].push_back(temp2);
		v[temp2].push_back(temp1);
	}
	for (int i = 0; i < n; i++)
	{
		sort(v[i].begin(), v[i].end());
	}
	cout << bfs();
	
}