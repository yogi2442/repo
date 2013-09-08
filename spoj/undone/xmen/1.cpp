#include <cstdio>
#include <iostream>
#include <cstdlib>


int main()
{
	int i,j,k,l,m,n,test,u,*A,*B,**C;

	scanf("%d",&test);
	for(u=0;u<test;u++)
	{
		scanf("%d",&n);
		A = (int*)malloc(sizeof(int)*(n+1));
		B = (int*)malloc(sizeof(int)*(n+1));
		C = (int**)malloc(sizeof(int*)*(n+1));
		C[0] = (int*)malloc(sizeof(int)*(n+1));
		for(i=1;i<=n;i++)
		{
			scanf("%d",&A[i]);
			C[i] = (int*)malloc(sizeof(int)*(n+1));
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&B[i]);
			C[i][0] = 0;
			C[0][i] = 0;
		}
		C[0][0]= 0;
		for(i=1;i<=n;i++)
		{
			if(A[i] == B[1])
				C[i][1] = 1;
			else
				C[i][1] = C[i-1][1];

			if(A[1] == B[i])
				C[1][i] = 1;
			else
				C[1][i] = C[1][i-1];
		}
		for(i=2;i<=n;i++)
		{
			for(j=2;j<=n;j++)
			{
				if(A[i] == B[j])
				{
					C[i][j] = C[i-1][j-1]+1;
				}
				else
				{	
					if(C[i-1][j] > C[i][j-1])
						C[i][j] = C[i-1][j];
					else
						C[i][j] = C[i][j-1];
				}
			}
		}
		free(A);
		free(C);
		free(B);
		printf("%d\n",C[n][n]);
	}
	return 0;
}
