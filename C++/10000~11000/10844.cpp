#include<iostream>
#include<cmath>

using namespace std;
const int DIV = 1000000000;
int n;
long long int cnt = 0;
int dp[101][10];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
				dp[i][0] = dp[i - 1][1] % DIV;
			else if (j == 9)
				dp[i][9] = dp[i - 1][8] % DIV;
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % DIV;
		}
	}
	for (int i = 1; i < 10; i++)
		cnt = (cnt + dp[n][i]) % DIV;
	printf("%d\n", cnt%DIV);
}

// 뒤 숫자가 앞 숫자(지금 숫자)의 -1 or +1