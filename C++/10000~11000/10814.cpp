#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;
const int MAX = 100000;
int n;
bool cmp(pair<int, string>u, pair<int, string> v)
{
	return u.first < v.first;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	vector<pair<int, string>> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}
	stable_sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < n; i++)
		cout << arr[i].first << " " << arr[i].second << '\n';
}