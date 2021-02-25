#include <stdio.h>

int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d\n%d\n%d\n%d\n%d\n%.2f",a+b,a-b,a*b,(int)a/b,a%b,(float)a/(float)b);
	
	return 0;
	
}
