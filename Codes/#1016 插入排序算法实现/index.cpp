#include <cstdio>
#include <cstring>

int num[111];
void Sort_num(int n)
{
	int i=1,j;
	int  temp=num[i];
	j=i;
	while(j >0 && num[j-1]>num[i])
		j--;
	int k;
	for(k=i-1;k>=j;k--)
		num[k+1]=num[k];
	num[j]=temp;
}

void Print(int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",num[i]);
}

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		int i;
		for(i=0;i<n;i++)
			scanf("%d",&num[i]);
		Sort_num(n);
		Print(n);
	}
	return 0;
}