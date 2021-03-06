#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
vector<pair<int, int>> table;	// START, END
int n;
int cnt = 0;
void conference()
{
	int value = 0;
	for (int i = 0; i < n; i++)
	{
		if (table[i].second >= value)
		{
			value = table[i].first;
			cnt++;
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int START, END;
		cin >> START >> END;
		table.push_back(make_pair(END, START));
	}
	sort(table.begin(), table.end());
	conference();
	cout << cnt;	
}