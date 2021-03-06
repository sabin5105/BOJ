#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
pair<int, int> arr[102];
int dp[102];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i].first >> arr[i].second;
		dp[i] = 1;
	}
	sort(arr, arr + n+1);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (arr[i].second > arr[j].second && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= n; i++)
		if (ans < dp[i])
			ans = dp[i];

	cout << n - ans;
}