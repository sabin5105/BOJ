#include<iostream>

using namespace std;

int arr[22];
int main()
{
	arr[0] = 0, arr[1] = 1;
	int n;
	cin >> n;

	if (n < 2) { cout << n << endl; return 0; }
	for (int i = 2; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	cout << arr[n];
}