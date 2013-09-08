#include <cstdio>
#include <iostream>
#include <cstdlib>

int A[1000001];

int main()
{
	int i,j,k,l,m,n;
	for(i=1;i<1000001;i++)
		A[i] = i;
	for(i=2;i<=1000000;i++)
	{
		if(A[i] == i)
		{
			for(j=2*i;j<=1000000;j=j+i)
			{
				A[j] = A[j] - A[j]/i;
			}
		}
		if(A[i-1] == i-1)
			A[i-1] = i - 2;
	}
	A[1] = 1;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		printf("%d\n",A[m]);
	}
	return 0;

}
