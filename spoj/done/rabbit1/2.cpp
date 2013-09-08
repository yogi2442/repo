#include <cstdio>
#include <cmath>

int main()
{
	int t,u,i,j,k,l,m;
	long long p,q,r,s,n;

	scanf("%d",&t);
	for(u=0;u<t;u++)
	{
		scanf("%lld",&n);
	//	s = pow(2,m);
		p = 0;
		q = 1;
		while(n--)
		{
			r = p + q;
			p = q;
			q = r;
		}
		printf("%lld\n",p);
	//	p = p / 2;
	//	printf("%lld\n",p%s);
	}
	return 0;
}
