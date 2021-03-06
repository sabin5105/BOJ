#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
int arr[7] = { 1,2,4,8,16,32,64 };
bool flag[7];
int k;
int cnt = 8;
void powerset(int n, int depth)
{
	if (n == depth) 
	{
		int sum = 0;
		int cmp = 0;
		for (int i = 0; i < n; i++) 
		{
			if (flag[i] == 1)
			{
				sum += arr[i];
				cmp++;
			}
		}
		if (sum == k)
		{
			cnt = min(cnt, cmp);
		}
		return;
	}
	flag[depth] = 1;
	powerset(n, depth + 1);
	flag[depth] = 0;
	powerset(n, depth + 1);
}

int main()
{
	cin >> k;

	powerset(sizeof(arr)/sizeof(int), 0);
	cout << cnt;
}
