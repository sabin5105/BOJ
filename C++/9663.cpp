#include<iostream>

using namespace std;
#define MAX 40

int n;
bool ROW[MAX];
bool RU[MAX];
bool RD[MAX];
int cnt=0;

void backtracking(int x)	//x는 행 
{
	if (x >= n + 1) cnt++;

	for (int i = 1; i <= n; i++)
	{
		if (ROW[i])	// 같은 열에 있으면	
			continue;
		if (RU[x + i] || RD[n + (x - i)])
			continue;

		ROW[i] = RU[x + i] = RD[n + (x - i)] = true;
		backtracking(x + 1);
		ROW[i] = RU[x + i] = RD[n + (x - i)] = false;
	}
}
int main()
{
	cin >> n;

	backtracking(1);
	cout << cnt << endl;
}