#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;


int main()
{
	int i,j,n,m,u,test,ans,k;
	scanf("%d",&test);
	for(u=0;u<test;u++)
	{
		scanf("%d%d",&n,&m);
		i = n - m;
		j = (m - 1)/2;
		k = i & j;
		if(k == 0)
			ans = 1;
		else
			ans = 0;
		printf("%d\n",ans);
	}
	return 0;
}

