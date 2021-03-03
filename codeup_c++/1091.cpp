#include <stdio.h>

int main()
{
	long long int a,m,d,n;
	scanf("%lld %lld %lld %lld",&a,&m,&d,&n);
	
	
	for (int i = 0; i<n-1;i++)
	{
		a= a*m +d;
	}
	printf("%lld",a);
}
