#include<iostream>
using namespace std;

int llen(int n)
{
	int len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return len;
}

int main()
{
	int n, k;
	cin >> n >> k;	// 20 23 6

	int len = 0;
	int i = 0;
	for (i = 1; i <= n; i++)
	{
		len += llen(i);
		if (len >= k)	break;
	}

	while (len > k)
	{
		i /= 10;
		len--;
	}
	if (len == k)
	{
		cout << i % 10 << endl;
	}
	else
		cout << -1 << endl;
}