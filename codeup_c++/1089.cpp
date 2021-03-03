#include <stdio.h>

int main()
{
	int a,d,n;
	scanf("%d %d %d",&a,&d,&n);
	
	
	for (int i = 0; i<n-1;i++)
	{
		a+=d;
	}
	printf("%d",a);
}
