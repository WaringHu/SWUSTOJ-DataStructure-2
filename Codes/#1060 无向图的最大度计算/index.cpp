#include <iostream>
using namespace std;

int main()
{

		int count[100];
		int n;
		cin >> n;
		int arr[1000][1000];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] == 1)
					count[i]++;
			}
		}
	int max = 0;
	int arr1[100];
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (count[i]>max)
			max = count[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (count[i] == max)
		{
			arr1[j] = i;
			j++;
		}
	}
	cout << max << endl;
	for (int i = 0; i < j; i++)
	{
		cout << arr1[i];
	}
	return 0;
}