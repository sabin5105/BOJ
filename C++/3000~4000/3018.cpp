#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, e;
int song[55][110];
vector<int> main_song;
vector<int> answer;

void without(int arr[], int size, int till)
{
	for (int i = 0; i < till; i++)
	{
		bool check = false;
		for (int j = 0; j < size; j++)
		{
			if (song[i][arr[j]] == 1)
			{
				check = true;
				break;
			}
		}
		if(check == true)
			for (int j = 0; j < size; j++)
			{
				song[i][arr[j]] = 1;
			}
	}
}
int main()
{
	cin >> n >> e;
	for (int i = 0; i < e; i++)
	{
		int temp;
		cin >> temp;
		
		bool check = false;
		int arr[55];
		for (int j = 0; j < temp; j++)
		{
			cin >> arr[j];
			song[i][arr[j]]++;
			if (arr[j] == 1)
			{
				check = true;
				main_song.push_back(i);
			}
		}
		if (check == false)
			without(arr, temp, i);
	}
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
	
		for (int k = 0; k < main_song.size(); k++)
		{
			if (song[main_song[k]][i] == 1)
				cnt++;
		}
		if (cnt == main_song.size())
			answer.push_back(i);
	}
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << endl;
}