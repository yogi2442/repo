#include <cstdio>

int main()
{
	long long u,t,n;
	scanf("%lld",&t);
	for(u=0;u<t;u++)
	{
		scanf("%lld",&n);
		n = n * 2;
		printf("Case %lld: %lld.25\n",u+1,n*n);
	}
	return 0;
}
