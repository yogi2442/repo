#include <stdio.h>
#include <stdlib.h>

int *A;

int func(long long int);

int main()
{
	int t,u,ans,i,j;
	long long int n;
	
	A = (int*)malloc(sizeof(int)*190000001);


	scanf("%d",&t);
	for(u=0;u<t;u++)
	{
		scanf("%lld",&n);
		printf("%d\n",func(n));
	}
	return 0;
}
int func(long long int n)
{
	if(n <= 4)
		return n;
	long long p,q,ans3;
	int ans1,ans2;

	p = n / 2;
	q = n - p;

	printf("n = %lld p = %lld q = %lld\n",n,p,q);
	if(p <= 190000000)
	{
		if(A[p] <= 0)
		{
			ans1 = func(p);
			A[p] = ans1;
		}
		else
			ans1 = A[p];
	}
	else
		ans1 = func(p);

	if(p != q)
	{
		if(q <= 190000000)
		{
			if(A[q] <= 0)
			{
				ans2 = func(q);
				A[q] = ans2;
			}
			else
				ans2 = A[q];
		}
		else
			ans2 = func(q);
	}
	else
		ans2 = ans1;

	ans3 = ans1*ans2;
	return (ans3) % 1000000007;
}
