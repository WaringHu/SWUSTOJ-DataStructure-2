#include <iostream>
using namespace std;

int id = 5;
int main()
{
	int n;
	int arr[1000];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		if (i + id<n)
		{
			if (arr[i]>arr[i + id])
			{
				temp = arr[i];
				arr[i] = arr[i + id];
				arr[i + id] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}