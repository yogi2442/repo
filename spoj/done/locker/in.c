#include <stdio.h>
int main()
{
	long long int i,j=1000000000000;
	printf("100000\n");
	for(i=0;i<100000;i++)
		printf("%lld\n",j--);
	return 0;

}
