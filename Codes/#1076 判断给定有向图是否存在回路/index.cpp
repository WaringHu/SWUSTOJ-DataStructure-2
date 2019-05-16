#include <iostream>
using namespace std;

int visit[100];
int data[100][100];
int n,m;
int p=0;
void DFSPath(int u,int v,int d)
{
	int queue[100],front=0,rear=0;
	int w,i;
	visit[u]=1;
	d++;
	rear=(rear+1)%100;
	queue[rear]=u;
	while(front!=rear)
	{
		front=(front+1)%100;
		w=queue[front];
		for(i=0;i<n;i++)
		{
			if(data[w][i]!=0&&i==v&&d>0)
			{
				p=1;
				return;
			}
			if(data[w][i]!=0&&visit[i]==0)
			{
				rear=(rear+1)%100;
				queue[rear]=i;
				visit[i]=1;
				DFSPath(i,v,d);
			}
		}
	}
}
int main(void)
{
	cin>>n;
	cin>>m;
	int i,j;
	char c[100];
	for(i=0;i<n;i++)
		cin>>c[i];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			data[i][j]=0;
		visit[i]=0;
	}
	for(i=0;i<m;i++)
	{
		char a,b;
		cin>>a;
		cin>>b;
		data[a-'A'][b-'A']=1;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			visit[j]=0;
		DFSPath(i,i,0);
	}
	if(p==1)
		cout<<"yes";
	else
		cout<<"no";
	return 0;
}