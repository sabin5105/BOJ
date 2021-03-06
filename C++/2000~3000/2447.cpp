#include<iostream>

using namespace std;

char map[3000][3000];
int n;
void reset()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			map[i][j] = ' ';
}
void ans(int n, int x, int y)
{
	if (n == 1) {
		map[x][y] = '*';
		return;
	}
	int div = n / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1)
				continue;
			ans(div, x + (div*i), y + (div*j));
		}
	}
	return;
}
int main()
{
	cin >> n;
	reset();
	ans(n, 0, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << map[i][j];
		cout << '\n';
	}
		
}