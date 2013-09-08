#include <stdio.h>
#include <math.h>

int main()
{
	int i,j,k,count;
	count = 0;
	for(i=2;i<=500000;i++)
	{
		k  = sqrt(i);
		for(j=2;j<=k;j++)
		{
			if(i % j == 0)
			{
				break;
			}
		}
		if(j == k+1)
		{
			count++;
			printf("%d\n",i);
		}
	}
	printf("count = %d\n",count);
	return 0;
}

