#include<iostream>

using namespace std;

int main()
{
	int MAX = 0;
	int index = 0;
	for (int i = 1; i < 10; i++)
	{
		int temp;
		cin >> temp;
		if (temp > MAX)
		{
			MAX = temp;
			index = i;
		}
	}
	cout << MAX << "\n" << index;

}