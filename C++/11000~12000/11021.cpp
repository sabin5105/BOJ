#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int temp1, temp2;
		cin >> temp1 >> temp2;
		cout << "case #" << i << ": " << temp1 + temp2 << endl;
	}
}