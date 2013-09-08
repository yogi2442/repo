#include <cstdio>
#include <iostream>
#include <cstdlib>

int main()
{
	int i,j,k,l,m,n;
	int sum1,sum2,sum;
	scanf("%d",&n);
	int *A,*B,flag1,flag2;
	while(n != 0)
	{
		flag1 = 0;
		flag2 = 0;
		A = (int*)malloc(sizeof(int)*n);
		
		for(i=0;i<n;i++)
			scanf("%d",&A[i]);
		
		scanf("%d",&m);
		
		B = (int*)malloc(sizeof(int)*m);
		
		for(i=0;i<m;i++)
			scanf("%d",&B[i]);
		sum1 = 0;
		sum2 = 0;
		sum = 0;

		i=0;j=0;

		while(i < n && j < m)
		{
			if(A[i] < B[j])
			{
				sum1 = sum1 + A[i++];
			}
			else if(A[i] > B[j])
			{
				sum2 = sum2 + B[j++];
			}
			else if(A[i] == B[j])
			{
				sum1 = sum1 + A[i++];
				sum2 = sum2 + B[j++];
				if(sum1 > sum2)
				{
					sum =  sum + sum1;
				}
				else
				{
					sum = sum + sum2;
				}
				sum1 = 0;
				sum2 = 0;
			}
		}
		while(i < n)
		{
			sum1 = sum1 + A[i++];
		//	flag1 = 1;
		}
		while(j < m)
		{
			sum2 = sum2 + B[j++];
		//	flag2 = 1;
		}
		if(sum1 > sum2)
			sum = sum + sum1;
		else
			sum = sum + sum2;

		printf("%d\n",sum);
		scanf("%d",&n);
		free(A);
		free(B);

	}
}
