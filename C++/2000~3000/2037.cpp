#include<iostream>
#include<string>
#include<cstring>

using namespace std;
int p,w;
int num[2][27] = 
{ 
	{ 1, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4 },	// 몇번 클릭?
	{ 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9 }		// 겹치는가?
};
int main()
{
	cin >> p >> w;

	string s;
	cin.ignore();
	getline(cin, s);

	int result = 0;
	int now = 0;
	for (int i = 0; i < s.length(); i++)
	{
		int index = -1;
		if (s[i] >= 'A' && s[i] <= 'Z') 
		{
			index = s[i] - 'A' + 1;	//ASKII
		}
		if (s[i] == ' ') 
		{
			index = 0;
		}
		if (index != -1) 
		{
			result += num[0][index] * p;
			if (now == num[1][index] && index != 0) // 같은거?
			{
				result += w;
			}
			now = num[1][index];
		}
	}
	cout << result;
}