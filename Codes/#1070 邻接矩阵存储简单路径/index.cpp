#include <iostream>
#include <vector>
using namespace std;

vector<int> path;
int visited[100];
int n;
int arr[100][100];
int First, End;
void find(int current)
{
	path.push_back(current);
	if (End == current)
	{
		for (int i = 0; i < path.size(); i++)
		{
			cout << path[i];
		}
		cout << endl;
		path.pop_back();
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (End != current&&visited[i] == 0 && arr[current][i]==1)
		{
			visited[i] = 1;
			find(i);
			visited[i] = 0;
		}
	}
	path.pop_back();
}
int main()
{
	cin >> n;
	cin >> First >> End;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++)
		visited[i] = 0;
	visited[First] = 1;
	find(First);
	return 0;
}