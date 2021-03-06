#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int recommend[101];
int main()
{
	int t;
	cin >> t;

	vector<pair<int, int>> table(t, { 0,0 });	// 시간, 사진
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		recommend[temp]++;

		bool replace = true;
		for (int j = 0; j < t; j++)	// 없거나 겹치는 게 있을 때
		{
			if (table[j].second == 0)
			{
				table[j].second = temp;
				table[j].first = i;
				replace = false;
				break;
			}
			else if (table[j].second == temp)
			{
				replace = false;
				break;
			}
			
		}
		if (replace)	// 꽉 차있고 겹치는게 없을 때 ; 바꿔야할 때
		{
			int index = 0;
			for (int j = 1; j < t; j++)
			{
				if (recommend[table[j].second] == recommend[table[index].second])
				{
					if (table[j].first < table[index].first)
						index = j;
				}
				else if (recommend[table[j].second] < recommend[table[index].second])
					index = j;
			}
			recommend[table[index].second] = 0;
			table[index].first = i;
			table[index].second = temp;
		}
	}
	vector<int> ans;
	for (int i = 0; i < t; i++)
		ans.push_back(table[i].second);
	sort(ans.begin(), ans.end());
	for (int i = 0; i < t; i++)
		cout << ans[i] << ' ';
}