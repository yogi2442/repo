#include <cstdio>

int main()
{
	int i,k,j,l,m,n,ans;
	int A[15];
	A[0]=1;
	for(i=1;i<15;i++)
		A[i] = A[i-1]*i;
	while(scanf("%d%d",&n,&k) != EOF)
	{
		ans = A[n];
		for(i=0;i<k;i++)
		{
			scanf("%d",&m);
			ans = ans / A[m];
		}
		printf("%d\n",ans);
	}
	return 0;
}
