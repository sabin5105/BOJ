#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int set[10];
int main()
{
	string n;
	cin >> n;

	int cnt = 0;
	int ans = 0;
	for (int i = 0; i < n.length(); i++)
	{
		set[n[i] - '0']++;
	}
	for (int i = 0; i < 10; i++)
	{
		if (i != 6 && i != 9)
		{
			ans = max(ans,set[i]);
		}
	}
	cout << max(ans,(set[6]+set[9] + 1)/2);
}