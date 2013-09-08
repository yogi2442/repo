#include <cstdio>
#include <iostream>

int main()
{
	long long int n,ans,pre;
	int test,u,i,m;

	scanf("%d",&test);
	for(u=0;u<test;u++)
	{
		scanf("%d",&m);
		pre = 1;
		ans = 1;
		for(i=0;i<m;i++)
		{
			scanf("%lld",&n);
			ans = ans + n;
			if(ans < 1)
			{
				pre = pre + (1 - ans);
				ans = 1;
			}
		}
		printf("Scenario #%d: %lld\n",u+1,pre);
	}

}
