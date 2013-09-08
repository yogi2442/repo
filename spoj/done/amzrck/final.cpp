#include <cstdio>
#include <iostream>
#include <cstdlib>

int main()
{
	long long test,u,i,j,k,n;
	long long yes[100],no[100];
	yes[0] = 1;
	yes[1] = 1;
	no[0] = 0;
	no[1] = 1;
	for(i=2;i<45;i++)
	{
		yes[i] = no[i-1];
		no[i] = yes[i-1] + no[i-1];
	}
	scanf("%lld",&test);
	for(u=0;u<test;u++)
	{
		scanf("%lld",&n);
		printf("%lld\n",yes[n]+no[n]);
	}
	return 0;
}
