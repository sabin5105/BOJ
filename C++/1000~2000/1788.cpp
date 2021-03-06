#include<iostream>
#include<cmath>

using namespace std;

const long long int dividend = 1000000000;
long long int n;
long long int dp[2000002];

void fibonacci(int n)	// when input, + 1000000
{
	int ABS = abs(n);

	if (n > 1000000)
	{
		cout << 1 << endl;
		for (int i = 1000002; i <= n; i++)
			dp[i] = (dp[i - 1] + dp[i - 2]) % dividend;

		cout << dp[n] << endl;
	}
	if (n < 1000000)
	{
		if (n % 2 == 1)
			cout << 1 << endl;
		else if (n % 2 == 0)
			cout << -1 << endl;

		for (int i = 999999; i >= n; i--)
			dp[i] = (-dp[i+1] + dp[i+2]) % dividend;
		cout << abs(dp[n]) << endl;
	}
}
int main()
{
	cin >> n;
	dp[1000000] = 0;
	dp[1000001] = 1;
	if (n == 0) 
	{
		cout << 0 << '\n' << 0;
		return 0;
	}
	else if (n == 1)
	{
		cout << 1 << '\n' << 1;
		return 0;
	}

	fibonacci(n + 1000000);

}