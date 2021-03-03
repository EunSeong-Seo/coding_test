#include <stdio.h>

int main(){
	int a[20][20]={};
	int x,y;
	int n=0;
	scanf("%d",&n);
	
	for (int i =1;i<=n;i++){
		scanf("%d %d",&x,&y);
		a[x][y]=1;
	}
	for (int i = 1;i<=19;i++)
	{
		for (int j=1;j<=19;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
