#include<iostream>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	
	if (c <= b)
	{
		cout << -1 << endl;
		return 0;
	}
	else
	{
		cout << (a / (c - b)) + 1 << endl;
	}
}