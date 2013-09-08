#include <stdio.h>
#include <stdlib.h>

void func(char*,int,int,int);
int counter;
int main()
{
	int i,j,k,l,m,n,s,count;
	scanf("%d",&n);
	char *array;
	array = (char*)malloc(sizeof(char)*((2*n)+1));
	m = (2*n)+1;
	for(i=0;i<m;i++)
		array[i] = '0';
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		scanf("%d",&s);
		array[s] = '[';
	}
	for(i=1;i<m;i++)
		printf("%c ",array[i]);
	printf("\n");
	if(array[m-1] == '[')
	{
		printf("0\n");
	}
	else
	{
		array[1] = '[';

		for(i=1;i<m;i++)
			printf("%c ",array[i]);
		printf("\n");
		
		count = 0;
		counter = 0;
		i = 1;
		func(array,count,i,m);

		printf("%d\n",counter);
	}
	return 0;
}

void func(char *array,int count,int i,int m)
{
	int j;

//	printf("count = %d and i = %d\n",count,i);
	if(count == 0 && i == m)
	{
		printf("patter found\n");
	for(j=1;j<m;j++)
		printf("%c ",array[j]);
	printf("\n");
		counter++;
		return;
	}
	if(count < 0)
		return;
	if(array[i] == '[')
	{
		func(array,count+1,i+1,m);
	}
	else
	{
		if(array[i] == '0')
		{
			array[i] = '[';
			func(array,count+1,i+1,m);
			array[i] = ']';
			func(array,count-1,i+1,m);
			array[i] = '0';
		}
	}
}
