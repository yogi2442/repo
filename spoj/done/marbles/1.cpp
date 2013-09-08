#include <stdio.h>

int main()
{
	long long sum,ans,ret,p,q,r;
	int t,n,k,u;
	scanf("%d",&t);
	for(u=0;u<t;u++)
	{
		scanf("%d%d",&n,&k);
		n--;
		k--;
		ans = 1;
		sum = 1;
		while(k > 0)
		{
			ans = ans * (n--);
			sum = sum * (k--);
			p = ans;
			q = sum;
			r = 1;
			while(r)
			{
				r = p % q;
				p = q;
				q = r;
			}
			ans = ans/p;
			sum = sum/p;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

