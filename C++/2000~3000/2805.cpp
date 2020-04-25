#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long int n, m;
long int value=0;
int out = 0;
vector<int> trees;
int main()
{

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		trees.push_back(temp);
	}
	sort(trees.begin(), trees.end(), greater<int>());

	int index = 0;
	for (int i = 1; i < n; i++)
	{
		int temp_value = value;
		value = value + (trees[i - 1] - trees[i])*i;
		index = i;

		if (value == m)
			break;
		else if (value > m)
		{
			for (int j = (trees[i - 1] - trees[i]);; j--)
			{
				int temp = j * i + temp_value;
				if (temp == m)
				{
					break;
				}
				out++;
			}
			break;
		}
	}

	cout << trees[index] + out;

}