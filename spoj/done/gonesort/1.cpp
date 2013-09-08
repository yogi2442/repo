#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int i,j,k,l,test,u,n,max,count;
	scanf("%d",&test);
	for(u=0;u<test;u++)
	{
		scanf("%d",&n);
		int *A,*B;
		A = (int*)malloc(sizeof(int)*n);
		B = (int*)malloc(sizeof(int)*n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&A[i]);
			B[i] = A[i];
		}
		sort(B,B+n);

		i=0;
		j=0;
		max=0;
		count=0;
		while(i<n)
		{
		//	printf("i = %d   ",i);
			count=0;
			j=0;
			while(j<n)
			{
				if(B[i] == A[j])
				{
					count++;
					i++;
				}
				j++;
			}
		//	printf("count = %d\n",count);
			if(max < count)
				max = count;
		}

		printf("%d\n",n-max);
	//	free(A);
	//	free(B);
	}
	return 0;
}
