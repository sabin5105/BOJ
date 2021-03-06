#include<iostream>
#include<algorithm>
using namespace std;

int n;
int arr[1005];
int dp[1005];
int cnt = 0;
int MIN = 0;
int MAX = 0;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++)
	{
		MIN = 0;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				if (MIN < dp[j])
					MIN = max(MIN, dp[j]);
			}
		}
		dp[i] = MIN + 1;
		if (MAX < dp[i])
			MAX = dp[i];
	}
	cout << MAX;
}