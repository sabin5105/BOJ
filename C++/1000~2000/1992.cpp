#include<iostream>
#include<string>
using namespace std;

int n;
string map[70];
string ans;

void cal(int x,int y, int N)
{
	if (N == 1)
	{
		cout << map[x][y];
		return;
	}

	int temp = 0;
	for (int i = x; i < x+N; i++)
	{
		for (int j = y; j < y + N; j++)
		{
			if (map[i][j] == '1')
				temp++;
		}
	}
	if (!temp)
		cout << 0;
	else if (temp == N * N)
		cout << 1;
	else
	{
		cout << '(';
		cal(x, y, N / 2);
		cal(x, y + N / 2, N / 2);
		cal(x + N / 2, y, N / 2);
		cal(x + N / 2, y + N / 2, N / 2);
		cout << ')';
	}
	return;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> map[i];

	cal(0, 0, n);
	cout << ans;
}