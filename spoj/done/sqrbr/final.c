#include <stdio.h>
#include <stdlib.h>

void func(char*,int,int,int,int);
int counter;
int main()
{
	int i,j,k,l,m,n,s,count,test,u;
	char *array;
	scanf("%d",&test);
	for(u=0;u<test;u++)
	{
		scanf("%d",&n);
		array = (char*)malloc(sizeof(char)*((2*n)+1));
		m = (2*n)+1;

		for(i=1;i<m;i++)
		{
			array[i] = '0';
		}
		scanf("%d",&k);
		for(i=0;i<k;i++)
		{
			scanf("%d",&s);
			array[s] = '[';
		}
		if(array[m-1] == '[')
		{
			printf("0\n");
		}
		else
		{
			array[1] = '[';

			count = 0;
			counter = 0;
			i = 1;
			func(array,count,i,m,k);

			printf("%d\n",counter);
		}
		free(array);
	}
	return 0;
}

void func(char *array,int count,int i,int m,int k)
{
//	printf("count = %d\n",count);
	if(count == 0 && i == m)
	{
		counter++;
		return;
	}
	if(array[i] == '[')
	{
		func(array,count+1,i+1,m,k-1);
		return;
	}
	else
	{
		if(array[i] == '0')
		{
			if(m-1-i-k >= count)
			{
				array[i] = '[';
				func(array,count+1,i+1,m,k);
			}
			if(count > 0)
			{
				array[i] = ']';
				func(array,count-1,i+1,m,k);
			}
			array[i] = '0';
			return;
		}
	}
}
