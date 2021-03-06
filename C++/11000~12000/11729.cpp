#include<iostream>
#include<vector>
using namespace std;
int n, cnt=0;


void hanoi(int n, int from, int aux ,int to)
{
	if (n == 1) {
		cnt++;
		printf("%d %d\n", from, to);
		return;
	}
	else {
		cnt++;
		hanoi(n - 1, from, to, aux);
		printf("%d %d\n", from, to);
		hanoi(n - 1, aux, from, to);
	}
}
int number_hanoi(int n)
{
	int num = 1;
	while (--n) {
		num = num * 2 + 1;
	}
	return num;
}
int main()
{
	cin >> n;
	printf("%d\n", number_hanoi(n));
	hanoi(n,1,2,3);

}