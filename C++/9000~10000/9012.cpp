#include<iostream>
#include<stack>
#include<string>

using namespace std;

int n;
string s;
int cnt = 0;

int main()
{
	cin >> n;
	while (n--)
	{
		cin >> s;
		stack<bool> check;
		bool flag = false;

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(')
				check.push(true);
			else if (s[i] == ')')
			{
				if (check.empty())
				{
					cout << "NO" << '\n';
					flag = true;
					break;
				}
				else
					check.pop();
			}
		}
		if (flag == true)
			continue;
		if (check.empty())
			cout << "YES";
		else
			cout << "NO";
		cout << '\n';
	}
}