#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)	// is b.second is bigger than a.second?
{
	if (a.second < b.second)
		return true;
	else if (a.second == b.second)
		if(a.first < b.first)
			return true;
	return false;
}
int main()
{
	int n;
	scanf("%d", &n);

	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;
	
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n; i++)
		printf("%d %d\n", v[i].first, v[i].second);

}