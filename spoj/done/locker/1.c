#include <stdio.h>
#include <stdlib.h>

int *A;

int func(long long int);

int main()
{
	int t,u,i,j,ans;
	long long int n;
	A = (int*)malloc(sizeof(int)*100000001);
	for(i=0;i<=100000000;i++)
		A[i]=0;
	scanf("%d",&t);
	for(u=0;u<t;u++)
	{
		scanf("%lld",&n);
		if(n <= 100000000)
		{
			if(A[n] != 0)
				ans = A[n];
			else
				ans = func(n);
		}
		else
			ans = func(n);
		printf("%d\n",ans%1000000007);
	}
	return 0;
}

int func(long long int n)
{
//	printf("%lld\n",n);
	if(n <= 4)
	{
		int yogi;
		yogi = n;
		return yogi;
	}
	else
	{
		if(n <= 100000000)
			if(A[n] != 0)
				return A[n];
		long long int p,q;
		int ans1,ans2,ans3;
		p = n/2;
		q = n - p;
		if(p <= 100000000)
		{
			if(A[p] != 0)
				ans1 = A[p];
			else
			{
				ans1 = func(p);
				A[p] = ans1;
			}
		}
		else
			ans1 = func(p);


		if(q != p)
		{
			if(q <= 100000000)
			{
				if(A[q] != 0)
					ans2 = A[q];
				else
				{
					ans2 = func(q);
					A[q] = ans2;
				}
			}
			else
				ans2 = func(q);
		}
		else
			ans2 = ans1;

		return (ans1*ans2)%1000000007;

	}
}
