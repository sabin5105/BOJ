#include<iostream>
using namespace std;

int n;
int arr[2200][2200];
int MINUS = 0, ZERO = 0, ONE = 0;

void cal(int x, int y, int N)
{
	int temp_ = 0, temp_0 = 0, temp_1 = 0;
	for (int i = x; i < x + N; i++) 
	{
		for (int j = y; j < y + N; j++) 
		{
			if (arr[i][j] == -1)
				temp_++;
			else if (arr[i][j] == 0)
				temp_0++;
			else if (arr[i][j] == 1)
				temp_1++;
		}
	}
	if (temp_ == N * N)
		MINUS++;
	else if (temp_0 == N * N)
		ZERO++;
	else if (temp_1 == N * N)
		ONE++;
	else
	{
		cal(x, y, N / 3);  // top
		cal(x, y + N / 3, N / 3);
		cal(x, y + (N / 3) * 2, N / 3);
		cal(x + N / 3, y, N / 3); // middle
		cal(x + N / 3, y + N / 3, N / 3);
		cal(x + N / 3, y + N / 3 * 2, N / 3);
		cal(x + N / 3 * 2, y, N / 3);	// bottom
		cal(x + N / 3 * 2, y + N / 3, N / 3);
		cal(x + N / 3 * 2, y + N / 3 * 2, N / 3);
	}
	return;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	cal(0, 0, n);
	cout << MINUS << '\n' << ZERO << '\n' << ONE;
}