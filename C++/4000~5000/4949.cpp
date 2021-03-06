#include<iostream>
#include<string>
#include<stack>
using namespace std;

string s;
int main()
{
	while (1)
	{
		getline(cin, s);
		if (s[0] == '.' && s.length() == 1)
			return 0;

		stack<char> para;
		bool flag = false;

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(')	// small
				para.push('(');
			else if (s[i] == ')')
			{
				if (!para.empty() && para.top() == '(')
				{
					para.pop();
				}
				else
				{
					flag = true;
					break;
				}
			}

			if (s[i] == '[')	// big
				para.push('[');
			else if (s[i] == ']')
			{
				if (!para.empty() && para.top() == '[')
					para.pop();
				else
				{
					flag = true;
					break;
				}
			}
		}
		if (flag == true)
		{
			cout << "no" << '\n';
			continue;
		}
		else
		{
			if (para.empty())
				cout << "yes";
			else
				cout << "no";
		}
		cout << '\n';
	}
}