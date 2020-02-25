#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int> v;
vector<int> arr;

void func(int index)
{
	if (index == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << endl;
		return;
	}
	for (int i = 0; i < v.size(); i++)
	{
		arr.push_back(v[i]);
		func(index + 1);
		arr.pop_back();
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	func(0);
}