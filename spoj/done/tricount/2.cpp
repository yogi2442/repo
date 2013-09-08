#include <cstdio>
#include <iostream>
#include <cstdlib>


int main()
{
	int test,u;
	long long n,m,ans;
	scanf("%lld",&test);
	for(u=0;u<test;u++)
	{
		scanf("%lld",&n);
		m = n-1;
		ans = n*n + (((m)*(m+1)*((2*m)+1))/6 + ((m)*(m+1))/2)/2;
		m = n/2;
		ans = ans + ((n+1)*(n+2)*(m-1))/2 - (((2*n)+3)*((((m)*(m+1)/2))-1)) + 2*((((m)*(m+1)*((2*m)+1))/6)-1);
		printf("%lld\n",ans);
	}
	return 0;

}
