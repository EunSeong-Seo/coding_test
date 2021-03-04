#include <stdio.h>

int main ()
{
	int a[20][20];
	int n;
	
	for(int i=1;i<=19;i++)
	{
		for (int j=1;j<=19;j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	
	
	scanf("%d",&n);
	int x[n];
	int y[n];
	
	for (int i=0;i<n;i++)
	{
	scanf("%d %d",&x[i],&y[i]);
	}
	
	for (int i =1; i<=19;i++)
	{
		for (int j =0; j<n;j++)
		{
			if(a[x[j]][i]==0)a[x[j]][i]=1;
			else a[x[j]][i]=0;
			
			if(a[i][y[j]]==0)a[i][y[j]]=1;
			else a[i][y[j]]=0;
		}
	}
	
	for(int i=1;i<=19;i++)
	{
		for (int j=1;j<=19;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	
}
