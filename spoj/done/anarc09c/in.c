#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i,j,k,l,m,n;
	for(i=0;i<100;i++)
	{
		printf("%d %d\n",rand()%1000000,rand()%1000000);
	}
	printf("0 0\n");
	return 0;
}
