#include <cstdio>
#include <cstdlib>

long long *A;

long long func(long long);

int main()
{
	A = (long long*)malloc(sizeof(long long)*100000001);
	long long t,u,i,j,k,l,n,m,ans;
//	for(i=0;i<=100000000;i++)
//		A[i]=0;
	A[0]=0;
	A[1]=1;
	A[2]=2;
	A[3]=3;
	A[4]=4;

	scanf("%lld",&t);
	for(u=0;u<t;u++)
	{
		scanf("%lld",&n);
		ans = func(n);
		printf("%lld\n",ans%1000000007);
	}
	return 0;
}

long long func(long long n)
{
//	printf("%lld\n",n);
	if(n <= 100000000)
		if(A[n] != 0)
			return A[n];
//	printf("yogi\n");
	long long p,q,ans1,ans2,ans3;
	p = n/2;
	q = n - p;
//	printf("p = %lld q = %lld\n",p,q);
	if(p <= 100000000)
	{
		if(A[p] != 0)
			ans1 = A[p];
		else
		{
			ans1 = func(p);
			A[p] = ans1%1000000007;
		}
	}
	else
		ans1 = func(p)%1000000007;
	if(p != q)
	{
		if(q <= 100000000)
		{
			if(A[q] != 0)
				ans2 = A[q];
			else
			{
				ans2 = func(q);
				A[q] = ans2%1000000007;
			}
		}
		else
			ans2 = func(q)%1000000007;
	}
	else
		ans2 = ans1;
	ans3 = (ans2*ans1)%1000000007;
	return ans3;
}
