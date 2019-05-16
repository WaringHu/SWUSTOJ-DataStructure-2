#include <iostream>
#include <stack>
using namespace std;

void find(int arr[100][100], int n, int visited[100], stack<int> &S)
{
	if (S.size() <= 0)
	{
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[S.top()][i] == 1 && visited[i] == 0)
		{
			visited[i] = 1;
			S.push(i);
			find(arr, n, visited, S);
			S.pop();
		}
	}
}
int main()
{
	stack<int> S;
	int visited[100];
	int n;
	int arr[100][100];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		visited[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		S.push(i);
		visited[i] = 1;
		find(arr, n, visited, S);
		int flag = 0;
		for (int i = 0; i < n; i++)
		{
			if (visited[i] == 0)
			{
				flag = 1;
			}
		}
		for (int i = 0; i < n; i++)
		{
			visited[i] = 0;
		}
		if (flag == 0)
			cout << i;
	}
	return 0;
}