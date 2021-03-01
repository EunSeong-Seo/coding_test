#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int i,sum=0;

	for(i=0;sum<n;i++){
		sum+=i;
		if(sum>=n)	printf("%d",i);

	}

}
