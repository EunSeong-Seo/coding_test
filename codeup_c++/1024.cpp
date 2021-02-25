#include <stdio.h>

int main()
{
	char a[20];
	scanf("%s",a);
	for(int i=0;a[i]!='\0';i++)
	{
		printf("\'%c\'\n",a[i]);
	}
	return 0;
	
}
