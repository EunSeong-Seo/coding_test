#include <stdio.h>

int main()
{
	int a=1;
	int sum =0;
	int c;
	scanf("%d",&c);
	while(a!=c+1)
	{
		if(a%2==0)sum+=a;
		a++;
	}
	printf("%d",sum);
}
