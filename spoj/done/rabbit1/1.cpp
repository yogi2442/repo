#include <cstdio>
#include <cmath>

int main()
{
	int t,u,i,j,k,l,m,n;
	long long p,q,r,s;

	scanf("%d",&t);
	for(u=0;u<t;u++)
	{
		scanf("%d%d",&n,&m);
		s = pow(2,m);
		p = 1;
		q = 2;
		while(--n)
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
