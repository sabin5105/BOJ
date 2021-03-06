#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define MAX 8

int n, m;
vector<int> v;
int arr[MAX];
bool visited[MAX];

void func(int index)
{
	if (index == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (visited[i])
		{
			continue;
		}
		visited[i] = true;
		arr[index] = v[i];
		func(index + 1);
		visited[i] = false;
	}
}

int main()
{
	cin >> n >> m;
	
	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());
	func(0);

}