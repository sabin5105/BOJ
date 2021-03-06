#include<stack>
#include<iostream>
#include<algorithm>
using namespace std;

int n;
stack<int> s;

int main()
{
	cin >> n;
	while (n--)
	{
		int temp;
		cin >> temp;
		if (temp != 0)
			s.push(temp);
		else if (temp == 0)
			s.pop();
	}
	int sum = 0;
	int size = s.size();
	for (int i = 0; i < size; i++)
	{
		sum += s.top();
		s.pop();
	}
	cout << sum;
}