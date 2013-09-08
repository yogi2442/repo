#include <stdio.h>

int main()
{
	int i;
	printf("300000\n");
	for(i=0;i<300000;i++)
		printf("%d\n",rand()%1000001);
	return 0;
}
