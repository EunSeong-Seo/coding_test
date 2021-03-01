#include <stdio.h>

int main()
{
	char c;
	char a= 'a';
	scanf("%c",&c);
	while(a!=c+1)
	{
		printf("%c ",a++);
	}
}
