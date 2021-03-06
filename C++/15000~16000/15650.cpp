#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int n, m;
int arr[9];
int cmp[9];

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++) 
		arr[i] = i;

	do
	{
		bool check = false;
		int cnt = 1;
		while (cnt < m && !check)
		{
			if (arr[cnt] < arr[cnt + 1])
			{
				check = false;
				cnt++;
				continue;
			}
			check = true;
		}
		if (check == false)
		{
			bool check_print = false;
			for (int i = 1; i <= m; i++)
			{
				if (cmp[i] != arr[i])
				{
					check_print = true;
					break;
				}
			}

			if (check_print == true)
			{
				for (int i = 1; i <= m; i++)
					cout << arr[i] << ' ';
				cout << '\n';
			}
		}			
		memcpy(cmp, arr, sizeof(arr));
	} while (next_permutation(arr + 1, arr + n + 1));

}