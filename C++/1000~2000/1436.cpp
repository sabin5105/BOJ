#include<iostream>
#include<string>
using namespace std;

int temp, n, flag, cnt;
string str;

int main()
{
	cin >> n;

	int i = 0;
	while (++i)
	{
		temp = i; flag = 0;
		while (temp)
		{
			if (temp % 1000 == 666) flag = 1;
			temp /= 10;
		}
		if (flag)
		{
			cnt++;
			if (cnt == n) break;
		}
	}
	cout << i << endl;
}