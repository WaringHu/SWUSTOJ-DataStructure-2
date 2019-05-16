#include <iostream>
using namespace std;

bool check(int arr[100],int i,int& n,int max)
{
	if (n <= 0)
		return true;
	int left = 2 * i + 1;
	int right = left + 1;
	if (left <= max-1)
	{
		if (arr[i] < arr[left])
		{
			n--;
			check(arr, left, n,max);
		}
		else
			return false;
	}
	if (right <= max-1)
	{
		if (arr[i] < arr[right])
		{
			n--;
			check(arr, right, n,max);
		}
		else
			return false;
	}
}
int main()
{
	int max;
	int n;
	int arr[100];
	cin >> max;
	n = max;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	if (check(arr, 0, n,max))
		cout << "Yes";
	else
		cout << "No";
	return 0;
}