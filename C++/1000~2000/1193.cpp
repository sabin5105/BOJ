#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int cnt = 0, i = 0;
	for (i = 0; i < n; i += cnt)
		cnt++;

	int temp_cnt = 1;
	int start = i - cnt + 1;
	for (start; start < n; start++)
	{
		temp_cnt++;
	}

	switch (cnt%2)
	{
	case 0:
		cout << temp_cnt << '/' << cnt+1 - temp_cnt << endl;
		break;
	case 1:
		cout << cnt+1 - temp_cnt << '/' << temp_cnt << endl;
		break;
	}


}