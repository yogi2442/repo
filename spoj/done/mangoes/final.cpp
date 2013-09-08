#include <cstdio>

int main()
{
	long long t,u,n,m;
	scanf("%lld",&t);
	for(u=0;u<t;u++)
	{
		scanf("%lld",&n);
		m = n;
		if(n%2 == 0)
			n = n-2;
		else
			n--;
		n = n/2;
		printf("%lld\n",(n*n)%m);
	}
	return 0;
}
