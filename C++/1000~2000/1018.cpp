#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n, m;
string arr[50];

string w_first[8] = {
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" }
};
string b_first[8] = {
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" }
};
int black(int y, int x)
{
	int cnt = 0;
	for (int i = y; i < y + 8; i++)
		for (int j = x; j < x + 8; j++)
			if (arr[i][j] != b_first[i - y][j - x])
				cnt++;
	return cnt;
}
int white(int y, int x)
{
	int cnt = 0;
	for (int i = y; i < y + 8; i++)
		for (int j = x; j < x + 8; j++)
			if (arr[i][j] != w_first[i - y][j - x])
				cnt++;
	return cnt;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)	cin >> arr[i];
	int ans = 50;
	for (int i = 0; i + 7 < n; i++)
		for (int j = 0; j + 7 < m; j++)
			ans = min(ans,min(black(i, j), white(i, j)));
	cout << ans << endl;

}