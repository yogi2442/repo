#include <cstdio>
int main()
{
	long long t,u,n,flag;
	scanf("%lld",&t);
	for(u=0;u<t;u++)
	{
		flag=0;
		scanf("%lld",&n);
		if(n % 3 != 0)
			flag=1;
		printf("%lld\n",(((n*2)/3)+flag)%1000000007);
	}
	return 0;
}
