#include<iostream>
using namespace std;

struct node
{
	int value;
	node* left;
	node* right;
};
struct node Tree[30];
int n;

void pre(node a)
{
	cout << (char)(a.value + 'A');
	if (a.left != NULL)
		pre(*a.left);
	if (a.right != NULL)
		pre(*a.right);
}
void inorder(node a)
{
	if (a.left != NULL)
		inorder(*a.left);
	cout << (char)(a.value + 'A');
	if (a.right != NULL)
		inorder(*a.right);
}
void post(node a)
{
	if (a.left != NULL)
		post(*a.left);
	if (a.right != NULL)
		post(*a.right);
	cout << (char)(a.value + 'A');
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		Tree[i].value = i;
	}
	for (int i = 0; i < n; i++)
	{
		char value, left, right;
		cin >> value >> left >> right;
		if (left != '.')
		{
			Tree[value - 'A'].left = &Tree[left - 'A'];
		}
		if (right != '.')
		{
			Tree[value - 'A'].right = &Tree[right - 'A'];
		}
	}
	pre(Tree[0]);
	cout << endl;
	inorder(Tree[0]);
	cout << endl;
	post(Tree[0]);
}