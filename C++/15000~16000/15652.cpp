#include<iostream>
#include<vector>
using namespace std;

vector<int> arr;
int n, m;
void dfs()
{
	if (arr.size() == m)
	{
		bool check = false;
		for (int i = 0; i < arr.size()-1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				check = false;
				break;
			}
			check = true;
		}
		if (check == true)
		{
			for (int i = 0; i < arr.size(); i++)
				cout << arr[i] << ' ';
			cout << '\n';
		}
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
	if (m == 1)
	{
		for (int i = 1; i <= n; i++)
			cout << i << endl;
		return 0;
	}
	dfs();

}