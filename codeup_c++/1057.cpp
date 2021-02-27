#include <stdio.h>

int main()
{
	int a ,b;
	scnaf("%d %d",&a,&b);
	printf("%d", !(a^b));
	return 0;
}
