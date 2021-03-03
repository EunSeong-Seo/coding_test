#include <stdio.h>

int main()
{
	long long int a,r,n;
	scanf("%lld %lld %lld",&a,&r,&n);
	
	
	for (int i = 0; i<n-1;i++)
	{
		a*=r;
	}
	printf("%lld",a);
}
