#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<pair<int, int>, int>> v;
void printOrder(void)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;
			else if (v[i].first.first < v[j].first.first && v[i].first.second < v[j].first.second)
				v[i].second++;
		}
	for (int i = 0; i < n; i++)
		cout << v[i].second << " ";
	cout << endl;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(make_pair(x, y), 1));
	}
	printOrder();

	return 0;
}