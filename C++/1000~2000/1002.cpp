#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t)
	{
		t--;
		int x1, x2, y1, y2, r1, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		double dis = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));	// 두 좌표간의 거리

		if (r2 + r1 == dis || fabs(r2-r1) == dis) {
			cout << 1 << endl;
			continue;
		}
		else if (r2 + r1 < dis || fabs(r2-r1) > dis) {
			cout << 0 << endl;
			continue;
		}
		else if (dis == 0 && r2 == r1) {
			cout << -1 << endl;
			continue;
		}
		else {
			cout << 2 << endl;
			continue;
		}
	}
}