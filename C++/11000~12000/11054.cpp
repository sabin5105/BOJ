#include<iostream>
using namespace std;

int arr[1001];
int dp[1001];
int R_dp[1001];
int n;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		for (int j = 1; j <= i; j++)
		{
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
	}
	for (int i = n; i >= 1; i--)
	{
		R_dp[i] = 1;
		for (int j = n; j >= i; j--)
		{
			if (arr[i] > arr[j] && R_dp[i] < R_dp[j] + 1)
				R_dp[i] = R_dp[j] + 1;
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; i++)
		if (ans < dp[i] + R_dp[i])
			ans = dp[i] + R_dp[i];
	cout << ans - 1;
}