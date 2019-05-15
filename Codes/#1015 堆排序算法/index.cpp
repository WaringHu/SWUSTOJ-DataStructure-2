#include <iostream>
using namespace std;

int arr[1000];
int n;
void sort(int i)
{
	int lchild = 2 * i + 1;
	int temp = arr[i];
	while (lchild < n)
	{
		if (lchild<n - 1 && arr[lchild]>arr[lchild + 1])
		{
			lchild++;
		}
		if (temp > arr[lchild])
		{
			arr[i] = arr[lchild];
			i = lchild;
			lchild = lchild * 2 + 1;
		}
		else
			break;
	}
	arr[i] = temp;
}
int main()
{
	
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = (n-1) / 2; i >= 0; i--)
	{
		sort(i);
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i]<<" ";
	}
	return 0;
}