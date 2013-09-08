#include <stdio.h>
#include <stdlib.h>
int compare(const void *a,const void *b)
{
	return(*(int*)a - *(int*)b);
}

int main()
{
	int test,i,j,n,sum;
	scanf("%d",&test);
	int *first,*second;
	for(i=0;i<test;i++)
	{
		scanf("%d",&n);
		first = (int*)malloc(sizeof(int)*n);
		second = (int*)malloc(sizeof(int)*n);
		for(j=0;j<n;j++)
			scanf("%d",&first[j]);
		for(j=0;j<n;j++)
			scanf("%d",&second[j]);
		qsort(first,n,sizeof(int),compare);
		qsort(second,n,sizeof(int),compare);
		sum = 0;
		for(j=0;j<n;j++)
		{
			sum = sum + (first[j] * second[j]);
		}
		printf("%d\n",sum);
		free(first);
		free(second);
	}

}
