#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
int arr[9];
int cmp[9];
bool CmpToCheck[9];
int main()
{
	int n,m;		// 길이 = n, 1~m 까지의 숫자
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		arr[i] = i;
	do
	{
		bool check = true;
		bool print = false;
		for (int i = 1; i <= m; i++)
		{
			if(cmp[i] == arr[i])
				CmpToCheck[i] = true;
		}
		for (int i = 1; i <= m; i++)
			if (CmpToCheck[i] == false)
				check = false;
		if (check == false)
		{
			for (int i = 1; i <= m; i++)
				cout << arr[i] << ' ';
			print = true;
		}
		if(print == true)
			cout << '\n';
		memcpy(cmp, arr, sizeof(arr));
		fill(CmpToCheck, CmpToCheck + m + 1, false);
	} while (next_permutation(arr+1, arr+n+1));

}