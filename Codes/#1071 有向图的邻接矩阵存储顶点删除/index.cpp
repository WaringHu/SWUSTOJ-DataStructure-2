#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int x;
	cin >> x;
	int temp = 0;
	int arr[100][100];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin>>arr[i][j];
		}
	}
	cout << n - 1<<endl;
	for (int i = 0; i < n; i++)
	{
		if (i != x)
			cout << i;
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i!=x&&j!=x)
			cout << arr[i][j];
		}
		if (i!=x)
		cout << endl;
	}
	return 0;
}