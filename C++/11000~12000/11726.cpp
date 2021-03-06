#include<iostream>

using namespace std;
const int divisor = 10007;
int n;
int arr[1000];
int dp[divisor];
int DP(int n)
{
	if (n <= 1)
		return 1;
	else if (n == 2)
		return 2;

	if (dp[n] != 0)
		return dp[n];
	else
	{
		dp[n] = (DP(n - 1) + DP(n - 2)) % divisor;
		return dp[n];
	}
}
int main()
{
	cin >> n;
	cout << DP(n);

}