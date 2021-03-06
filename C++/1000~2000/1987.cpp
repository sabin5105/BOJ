#include<iostream>
#include<algorithm>

using namespace std;
int R,C;
char map[22][22];
bool alphabet[26];
int ans = 1;

typedef struct
{
	int dx, dy;
}dir;
dir direction[4] = { {0,1},{1,0},{-1,0},{0,-1} };

void solution(char map[][22], bool alphabet[], int x, int y, int cnt)
{
	for (int k = 0; k < 4; k++)
	{
		int newX = x + direction[k].dx;
		int newY = y + direction[k].dy;
		if (newY >= 1 && newY <= C && newX >= 1 && newX <= R && !alphabet[map[newX][newY] - 'A'])
		{
			alphabet[map[newX][newY] - 'A'] = true;
			solution(map, alphabet, newX, newY, cnt+1);
			alphabet[map[newX][newY] - 'A'] = false;
		}
	}
	ans = max(ans, cnt);
}

int main()
{
	cin >> R >> C;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			cin >> map[i][j];

	alphabet[map[1][1] - 'A'] = true;
	solution(map, alphabet,1,1,1);

	cout << ans;
}