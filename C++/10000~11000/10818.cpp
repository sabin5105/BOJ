#include<iostream>
#include<algorithm>
using namespace std;

int MAX = -1000001;
int MIN = 1000001;
int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		MAX = max(temp, MAX);
		MIN = min(temp, MIN);
	}
	cout << MIN << ' ' <<  MAX;
}