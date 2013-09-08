#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

int **c;
char A[2][100009],ch;

void dfs(int,int);

int main()
{
	int n,i,j,k,l,m;
	scanf("%d",&n);
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
	//	printf("%c",A[0][i]);
		c[A[0][i]-65][0]--;
	}
//	printf("\n");
//	scanf("%c",&ch);

	for(i=0;i<4;i++)
	{
		if(A[0][0] != 1+c[i][1] && c[i][0] > 0)
		{
			A[1][0] = 64+c[i][1];
			c[i][0]--;
			dfs(1,m);
			c[i][0]++;
		}
	}
	return 0;
}

void dfs(int i,int m)
{
	int j;
	if(i == m)
	{
		for(i=0;i<m;i++)
		{
			if(i == m-1)
				printf("%c\n",A[1][i]);
			else
				printf("%c",A[1][i]);
		}
		exit(0);
	}
	for(j=0;j<4;j++)
	{
		if(A[0][i] != 64+c[j][1]  && A[1][i-1] != 64+c[j][1] && c[j][0] > 0)
		{
			A[1][i] = 64+c[j][1];
			c[j][0]--;
			dfs(i+1,m);
			c[j][0]++;
		}	
	}
}

