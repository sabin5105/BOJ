#include<iostream>
#include<cstring>
#include<string>
using namespace std;
#pragma warning(disable:4996)

int arr[100];	//65~90 A to Z

int main()
{
	int n;
	cin >> n;
	do
	{
		n--;
		string message;
		cin >> message;

		string ans;
		bool for_break = false;

		for (int i = 0; i < message.size(); i++) {
				
			ans += message[i];
			arr[(int)message[i]]++;
			for (int j = 65; j < 91; j++) {

				if (arr[j] == 3) {
					arr[j] = 0;
					ans += message[i];
					if (message[i + 1] != message[i]) {
						cout << "FAKE" << endl;
						for_break = true;
					}
					else if (message[i + 1] == message[i])
					{
						i++;
						break;
					}
				}
				if (for_break == true)
					break;
			}
			if (for_break == true)
				break;
		}
		if(for_break == false)
			cout << "OK" << endl;

		fill(arr + 65, arr + 91, 0);
	} while (n > 0);
}