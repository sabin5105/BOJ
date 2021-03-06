#include<iostream>
#include<cmath>
using namespace std;

int n;
int arr[130][130];
int white = 0, blue = 0;

void cal(int x, int y, int N)
{
	int temp = 0;
	for (int i = x; i < x + N; i++)
	{
		for (int j = y; j < y + N; j++)
		{
			if (arr[i][j])
				temp++;
		}
	}
	if (!temp)
		white++;
	else if (temp == N * N)
		blue++;
	else
	{
		cal(x, y, N / 2);
		cal(x, y + N / 2, N / 2);
		cal(x + N / 2, y, N / 2);
		cal(x + N / 2, y + N / 2, N / 2);
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

	cout << white << '\n' << blue;
	
}