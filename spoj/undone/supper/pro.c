#include <stdio.h>
int main()
{
	int i,j;
	printf("100000\n");
	for(i=0;i<100000;i++)
	{
		j = rand() % 1000000000;
		printf("%d\n",j);
	}
	return 0;
	
}
