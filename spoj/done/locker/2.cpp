#include <cstdio>
#include <cstdlib>

int *A;

int func(long long);

int main()
{
	A = (int*)malloc(sizeof(int)*100000001);
	long long n,yogi;
	int ans,t,u,i,a,b;
	
	A[1] =1;
	A[2] =2;
	A[3] =3;
	A[4] =4;

/*	for(i=5;i<=10000000;i++)
	{
		a = i/2;
		b = i - a;
		yogi = (A[a]*A[b])%1000000007;
		A[i] = yogi;
	}

*/
	scanf("%d",&t);
	for(u=0;u<t;u++)
	{
		scanf("%lld",&n);
	/*	if(n <= 10000000)
			ans = A[n];
		else*/
			ans = func(n);
		printf("%d\n",ans);
	}
	return 0;
}

int func(long long n)
{
	if(n <= 4)
		return n;
	if(n <= 100000000)
		if(A[n] != 0)
			return A[n];
	long long p,q,ans1,ans2,ans3;
	p = n/2;
	q = n - p;
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
	return (ans2*ans1)%1000000007;
}
