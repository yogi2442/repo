#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int n,i,j,k,l,m;
	char A[2][100009],ch;
	scanf("%d",&n);
	int **c;
	c = (int**)malloc(sizeof(int*)*4);
	for(i=0;i<4;i++)
		c[i] = (int*)malloc(sizeof(int)*2);
	c[0][0] = n;
	c[1][0] = n;
	c[2][0] = n;
	c[3][0] = n;

	c[0][1] = 1;
	c[1][1] = 2;
	c[2][1] = 3;
	c[3][1] = 4;
	
	scanf("%c",&ch);
	scanf("%c",&ch);
	m = 2*n;
	for(i=0;i<m;i++)
	{
		scanf("%c",&A[0][i]);
		printf("%c",A[0][i]);
		c[A[0][i]-65][0]--;
	}
	printf("\n");
	scanf("%c",&ch);	
	int *temp,max;
	for(i=0;i<4;i++)
	{
		max = i;
		for(j=i+1;j<4;j++)
		{
			if(c[max][0] <= c[j][0])
			{
				max = j;
			}
		}
		temp = c[max];
		c[max] = c[i];
		c[i] = temp;
	}
	for(i=0;i<4;i++)
	{
		if(A[0][0] != 1+c[i][1] && c[i][0] > 0)
		{
			A[1][0] = 64+c[i][1];
			c[i][0]--;
			break;
		}
	}
	printf("%c",A[1][0]);
	int count = 1,count1;
	for(k=1;k<m;k++)
	{
		count1 = count;
		for(i=0;i<4;i++)
		{
			max = i;
			for(j=i+1;j<4;j++)
			{
				if(c[max][0] <= c[j][0])
				{
					max = j;
				}
			}
			temp = c[max];
			c[max] = c[i];
			c[i] = temp;
		}
		for(i=0;i<4;i++)
		{
			if(A[0][k] != 64+c[i][1]  && A[1][k-1] != 64+c[i][1] && c[i][0] > 0)
			{
				A[1][k] = 64+c[i][1];
				c[i][0]--;
				count++;
				break;
			}
		}
			if(count1 == count)
			{
				printf("\n\nk = %d\n",k);
				for(i=0;i<4;i++)
				{
					printf("%d   %d\n",c[i][1],c[i][0]);
				}
				exit(0);
			}
		if(A[1][k] >= 65 && A[1][k] <= 68)
		{
			if(k == m-1)
				printf("%c\n",A[1][k]);
			else
				printf("%c",A[1][k]);
		}
	}
	printf("count = %d\n",count);
	return 0;
}
