#include <iostream>

using namespace std;

int main() 
{
	int p[6];
	int x, y;

	for (int i = 0; i < 6; i++) 
	{
		cin >> p[i];
	}

	if (p[0] == p[2]) 
	{
		x = p[4];
	}
	else if (p[0] == p[4]) x = p[2];
	else x = p[0];

	if (p[1] == p[3]) 
	{
		y = p[5];
	}
	else	if (p[1] == p[5]) y = p[3];
	else y = p[1];

	cout << x << " " << y << "\n";
}