#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 20;
const int INF = 987654321;

int N, result;
int team[MAX][MAX];

void DFS(string bit, int startTeam, int linkTeam)
{
	if (bit.size() == N)
	{
		vector<int> start, link;

		for (int i = 0; i < bit.length(); i++)
			if (bit[i] == '1')
				start.push_back(i);
			else
				link.push_back(i);

		int startTeamSum = 0;
		for (int i = 0; i < start.size(); i++)
			for (int j = i + 1; j < start.size(); j++)
				startTeamSum += (team[start[i]][start[j]] + team[start[j]][start[i]]);

		int linkTeamSum = 0;
		for (int i = 0; i < link.size(); i++)
			for (int j = i + 1; j < link.size(); j++)
				linkTeamSum += (team[link[i]][link[j]] + team[link[j]][link[i]]);

		result = min(result, abs(startTeamSum - linkTeamSum));
		return;
	}
	if (startTeam < (N / 2))
		DFS(bit + "1", startTeam + 1, linkTeam);
	if (linkTeam < (N / 2))
		DFS(bit + "0", startTeam, linkTeam + 1);
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> team[i][j];

	result = INF;
	DFS("", 0, 0);
	cout << result << "\n";
	return 0;

}