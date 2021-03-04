#include <stdio.h>

int main()
{
	int w,h;
	int n;
	
	scanf("%d %d",&w,&h);
	int a[w+1][h+1]={};
	
	scanf("%d", &n);
	int l[n],d[n],x[n],y[n];
	for (int i=1;i<=n;i++)
	{
		scanf("%d %d %d %d",&l[i],&d[i],&x[i],&y[i]);
		
		if(d[i]==0){
			for(int j=0;j<l[i];j++){
				a[x[i]][y[i]+j]=1;
			}
		}
		else if(d[i]==1){
			for(int j=0;j<l[i];j++){
				a[x[i]+j][y[i]]=1;
			}
		}
	
	}
	for (int i=1;i<=w;i++)
	{
		for (int j=1;j<=h;j++){
			printf("%d ",a[i][j]);}
		printf("\n");}
	
}
