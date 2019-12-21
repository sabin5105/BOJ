#include<iostream>
#include<vector>
using namespace std;

vector<int> arr;
int n, m;
void dfs()
{
	if (arr.size() == m)
	{
		for (int i = 0; i < arr.size(); i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (arr.size() < m)
		{
			arr.push_back(i);
			dfs();
			arr.pop_back();
		}
	}
}
int main()
{
	cin >> n >> m;
	dfs();
	
}