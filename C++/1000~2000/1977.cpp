#include<iostream>
#include<algorithm>
using namespace std;

int square;
int m, n;
int sum = 0;
bool check = false;
int MIN = 10001;
void calculate()
{
	for (int i = 1; i <= 100; i++)
	{
		square = i * i;
		if (m <= square && square <= n)
		{
			check = true;
			sum += square;
			MIN = min(MIN, square);
		}
	}
}
int main()
{
	cin >> m >> n;

	calculate();
	if (check == false)
	{
		cout << -1;
		return 0;
	}
	cout << sum << '\n' << MIN;
}