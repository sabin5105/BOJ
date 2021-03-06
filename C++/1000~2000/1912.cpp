#include<iostream>
using namespace std;

const int LAR = 100001;
int arr[LAR];
long long int dp[LAR];
long long int n;

int max(long long int a, long long int b)
{
	if (a > b)
		return a;
	return b;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	dp[0] = arr[0];
	int MAX = dp[0];
	for (int i = 0; i < n - 1; i++)
	{
		int temp = dp[i] + arr[i+1];
		dp[i + 1] = max(temp, arr[i + 1]);
		MAX = max(MAX, dp[i + 1]);
	}
	cout << MAX << endl;
}