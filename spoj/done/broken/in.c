#include <stdio.h>

int main()
{
	int i,j,k,l,m,n;
	for(i=0;i<100;i++)
	{
		j = rand()%26 + 1;
		printf("%d\n",j);
		k = rand()%100 + 1;
		while(k)
		{
			printf("%c",97+rand()%26);
			k--;
		}
		printf("\n");
	}
	printf("0\n");
	return 0;
}
