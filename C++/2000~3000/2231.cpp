#include<iostream>
#include<cmath>
using namespace std;

int cal(int input)
{
	int sum = 0;
	for (int i = pow(10, (int)log10(input)); i > 0; i /= 10)
	{
		sum += input / i;
		input = input % i;
	}
	return sum;
}

int main()
{
	int n;
	cin >> n;

	int temp = n;
	int min = 1000001;
	while (temp > 0)
	{
		temp--;
		if (n == temp + cal(temp)) {
			if (min > temp)
				min = temp;
		}
	}
	if (min == 1000001) {
		cout << 0 << endl;
		return 0;
	}
	cout << min << endl;
}