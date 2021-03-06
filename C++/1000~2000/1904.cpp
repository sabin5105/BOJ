#include<iostream>
using namespace std;

const int MOD = 15746;
const int MAX = 1000000;

int n;
int cache[MAX + 1];

int binary()
{
	cache[1] = 1;
	cache[2] = 2;
	for (int i = 3; i <= n; i++)
		cache[i] = (cache[i - 2] + cache[i - 1]) % MOD;
	return cache[n] % MOD;
}

int main()
{
	cin >> n;
	if (n > MAX)
		exit(-1);
	cout << binary() << endl;
}