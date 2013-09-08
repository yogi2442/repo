#include <cstdio>
#include <iostream>

int main()
{
	long long int  a,b,c,m;
	int test,u;
	scanf("%d",&test);
	for(u=0;u<test;u++)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		m = (a*a) - (2*b);
		printf("%lld\n",m);
	}
	return 0;
}
