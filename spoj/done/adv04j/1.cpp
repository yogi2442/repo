#include <cstdio>

int main()
{
	int A[30],i,j,n,l,m,test,u;
	A[0] = 1;
	for(i=1;i<30;i++)
	{
		A[i] = A[i-1] * 2;
	}
	scanf("%d",&test);
	for(u=0;u<test;u++)
	{
		scanf("%d",&n);
		for(i=0;i<30;i++)
			if(A[i] >= n)
				break;
		printf("%d\n",i+1);
	}
	return 0;

}
