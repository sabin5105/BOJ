#include<iostream>
#include<stack>
#include<string>

using namespace std;

int n;
string order;
stack<int> s;

int main()
{
	cin >> n;
	while (n--)
	{
		cin >> order;
		if (order == "push")
		{
			int temp;
			cin >> temp;
			s.push(temp);
			continue;
		}
		else if (order == "pop")
		{
			if (!s.empty())
			{
				cout << s.top();
				s.pop();
			}
			else
				cout << -1;
		}
		else if (order == "size")
		{
			cout << s.size();
		}
		else if (order == "empty")
		{
			if (s.empty())
				cout << 1;
			else
				cout << 0;
		}
		else if (order == "top")
		{
			if (!s.empty())
				cout << s.top();
			else
				cout << -1;
		}
		cout << '\n';
	}
}