#include <stdio.h>

int main()
{
	long int h,b,c,s;
	scanf("%ld %ld %ld %ld",&h,&b,&c,&s);
	
	long int PCM1 = (h*b);
	double PCM2 = c*s/1024;
	printf("%d\n",PCM1*PCM2);
	
	printf("%.1lf MB",PCM2/(8*1024));
}
