#include <cstdio>
#include <iostream>
#include <cstdlib>

int main()
{
	int i,j,k,l,m,n,test,u,A[25][25],B[50];
	scanf("%d",&test);
	for(u=0;u<test;u++)
	{
		for(i=0;i<50;i++)
			B[i]=0;
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++)
		{
			scanf("%d",&j);
			B[j] = 1;
		}
		for(i=0;i<=n;i++)
			A[i][0] = 1;
		for(i=0;i<=n;i++)
			A[0][i] = 0;
		for(i=0;i<24;i++)
			A[i][i+1] = 0;
		for(i=1;i<=n;i++)
		{
		//	printf("i = %d\n",i);
			for(j=1;j<=i;j++)
			{
			//	printf("j = %d  ,",j);
				if(B[i+j] == 1)
					A[i][j] = A[i-1][j];
				else
					A[i][j] = A[i-1][j] + A[i][j-1];
		//		printf("%d ",A[i][j]);
			}
		//	printf("\n");
		}
		printf("%d\n",A[n][n]);
	}
	return 0;
}
