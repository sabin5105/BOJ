#include<iostream>
#include<algorithm>
using namespace std;

int n;
int MAX = 0;
bool prime(int num)
{
	bool flag = true;
	for (int i = 2; i*i <= num; i++)
	{
		if (num % i == 0)
		{
			flag = false;
			break;
		}
	}
	return flag;
}
int main()
{
	scanf("%d", &n);
	int cnt = 0;
	if (n == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	if (n == 2)
	{
		cout << 1 << endl;
		return 0;
	}

	bool temp = prime(n);
	switch (temp)
	{
	case true:
		printf("%d", n - 1);
		break;
	case false:
		for (int i = 2; i*i <= n; i++)
		{
			if (n%i == 0)
			{
				MAX = max(MAX, max(i, n / i));
				break;
			}
			if (i*i == n)
			{
				MAX = i;
				cout << n - MAX;
				return 0;
			}
		}
		cout << n - MAX;
	}
}