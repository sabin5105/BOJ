#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int ans = 1;
	int condition = 1;

	int i = 0;
	while (condition < n)
	{
		i++;
		condition += 6 * i;
		ans++;
	}
	cout << ans;
}