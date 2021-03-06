#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<pair<int, int>> condo;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp_c,temp_d;
		cin >> temp_d >> temp_c;
		condo.push_back(make_pair(temp_d, temp_c));
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		bool flag = false;
		for (int j = 0; j < n; j++)
		{
			if (i != j && condo[i].first > condo[j].first && condo[i].second >= condo[j].second)
			{
				flag = true;
				break;
			}
			if (i != j && condo[i].first >= condo[j].first && condo[i].second > condo[j].second)
			{
				flag = true;
				break;
			}
		}
		if (flag == false)
			ans++;
	}
	cout << ans;
}