#include<iostream>

using namespace std;

const int dividend = 10007;
int arr[1001] = {1,1,3};
int n;
int main()
{
	cin >> n;
	for (int i = 3; i <= n; i++)
	{
		arr[i] = (arr[i - 1] + arr[i - 2]*2) % dividend;
	}
	cout << arr[n];
}