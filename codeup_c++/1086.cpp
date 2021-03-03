#include <stdio.h>

int main()
{
	long int w,h,b;
	scanf("%ld %ld %ld",&w,&h,&b);
	
	double CSL = w*h*b/8;

	printf("%.2lf MB",CSL/(1024*1024));
}
