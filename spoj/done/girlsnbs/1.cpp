#include <cstdio>

int main()
{
	int n,m,i,j,ans;
	scanf("%d%d",&n,&m);
	while(n != -1 && m != -1)
	{
		if(n == 0 && m == 0)
		{
			printf("0\n");
			scanf("%d%d",&n,&m);
			continue;
		}
		if(n < m)
		{
			n++;
			ans = m/n;
			if(m%n)
				ans++;
		}
		else
		{
			m++;
			ans = n/m;
			if(n%m)
				ans++;
		}
		printf("%d\n",ans);
		scanf("%d%d",&n,&m);
	}
	return 0;
}
