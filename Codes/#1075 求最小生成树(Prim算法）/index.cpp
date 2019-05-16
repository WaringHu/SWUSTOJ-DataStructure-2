#include <iostream>
using namespace std;

int n, e;
int mpt[200][200];
void prim()
{
	int lowcost[200], closest[200];
	int i, j, k, min;
	for (i = 0; i<n; i++)//初始化最近边为0-i、最近顶点为0。
	{
		closest[i] = 0;
		lowcost[i] = mpt[0][i];
	}
	lowcost[0] = -1;//标记0已加入G。
	for (i = 1; i<n; i++)//找到n-1个顶点。
	{
		min = 32768;
		for (j = 0; j<n; j++)//在没加如G中的顶点中找到最近顶点加入G。
		if (lowcost[j] != -1 && lowcost[j]<min)
		{
			min = lowcost[j];
			k = j;
		}
		cout << "(" << char(closest[k] + 'A') << ',' << char(k + 'A') << ')';
		lowcost[k] = -1;//标记k已加入G。
		for (j = 0; j<n; j++)//修改k到其他顶点的距离和顶点。
		if (mpt[k][j]<lowcost[j])
		{
			lowcost[j] = mpt[k][j];//更新最小值。
			closest[j] = k;//记录到j最近的顶点为k。
		}
	}
}
int main()
{
	char ash, a, b;
	int i, j, k;
	cin >> n >> e;
	for (i = 0; i<n; i++)
		cin >> ash;
	for (i = 0; i<n; i++)//初始化最最大值。
	for (j = 0; j<n; j++)
		mpt[i][j] = 9999;
	for (i = 0; i<e; i++)
	{
		cin >> a >> b >> k;
		a -= 'A'; b -= 'A';
		mpt[a][b] = k;
		mpt[b][a] = k;
	}
	prim();
	return 0;
}