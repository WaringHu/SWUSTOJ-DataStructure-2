//强联通图的判断是：判断任意两个顶点之间是否存在一条通路使之相连。
#include <iostream>
using namespace std;

int map[100][100];
int vis[100];
int n;
int flag = 0;
int check(int x,int y)
{
	if (x == y)
	{
		flag = 1;
		return 1;
	}
	if (x!=y)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[x][j] == 1 && vis[j] == 0)
			{
				vis[j] = 1;
				check(j,y);
				vis[j] = 0;
			}
		}
	}
	return 0;
}
int main()
{
	int x, y;
	int m;
	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			map[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		vis[i] = 0;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> x;
		cin >> y;
		map[x][y] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				for (int i = 0; i < n; i++)
					vis[i] = 0;
				flag = 0;
				check(i, j);
				if (flag!= 1)
				{
					cout<<"no";
					return 0;
				}
			}
		}
	}
	cout << "yes";
	return 0;
}