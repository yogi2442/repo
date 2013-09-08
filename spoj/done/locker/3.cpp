#include <cstdio>
#include <cstdlib>


int func(long long);

int main()
{
	long long n;
	int ans,t,u;

	scanf("%d",&t);
	for(u=0;u<t;u++)
	{
		scanf("%lld",&n);
		ans = func(n);
		printf("%d\n",ans%1000000007);
	}
	return 0;
}

int func(long long n)
{
	if(n <= 4)
		return n;
	else
	{
		long long p,q;
		int ans1,ans2,ans3;
		p = n/2;
		q = n - p;
		ans1 = func(p);
		if(q != p)
			ans2 = func(q);
		else
			ans2 = ans1;
		return (ans1*ans2)%1000000007;
	}
}
