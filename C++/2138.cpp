#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int n, ans = 987654321;
string start,temp,goal;

void button(int index)
{
	if (index > 0)
		temp[index - 1] = (temp[index - 1] == '0') ? '1' : '0';
	temp[index] = (temp[index] == '0') ? '1' : '0';
	if(index < n-1)
		temp[index + 1] = (temp[index + 1] == '0') ? '1' : '0';

	return;
}
void simulation(int index, int cnt)
{
	if (index == n - 1)
	{
		// 마지막에 안눌러도 일치?
		bool flag = true;
		for(int i=0;i<temp.length();i++)
			if (temp[i] != goal[i])
			{
				flag = false;
				break;
			}
		if (flag)
			ans = min(ans, cnt);

		// 마지막에 눌러야 일치?
		button(index);
		flag = true;
		for (int i = 0; i<temp.length(); i++)
			if (temp[i] != goal[i])
			{
				flag = false;
				break;
			}
		if (flag)
			ans = min(ans, cnt+1);

		return;
	}

	// 누른거랑 안누른거 둘다 재귀로 판단
	if (temp[index - 1] == goal[index - 1])
		simulation(index + 1, cnt);
	button(index);
	if (temp[index - 1] == goal[index - 1])
		simulation(index + 1, cnt+1);
	button(index);
}
int main()
{
	cin >> n >> start >> goal;

	// 0번째 스위치 누르지 않은 채 시작
	temp = start;	
	simulation(1, 0);

	// 0번째 스위치 누르고 시작
	temp = start;
	button(0);
	simulation(1, 1);

	
	if (ans == 987654321)
		cout << -1 << endl;
	else
		cout << ans << endl;

}