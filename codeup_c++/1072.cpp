#include <stdio.h>

int main()
{
	int n;
	int a;
	int c=0;
	scanf("%d", &n);
reload:
	scanf("%d", &a);
	printf("%d\n",a);
	c++;
	if(c!=n) goto reload;
}
