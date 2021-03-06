#include<iostream>
#include<algorithm>
using namespace std;

int arr[10002], dp[10002], n;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];

	for (int i = 3; i <= n; i++) 
	{ 
		dp[i] = max(dp[i - 3] + arr[i] + arr[i - 1], dp[i - 2] + arr[i]); // 2번 연속vs1번 연속
		dp[i] = max(dp[i - 1], dp[i]);	// 0번
	}
	cout << dp[n];
}