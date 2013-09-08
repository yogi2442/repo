#include <cstdio>
#include <cstdlib>

int main()
{
	int n,test,u,ans;
/*	A = (int*)malloc(sizeof(int)*1000001);
	for(i=0;i<1000001;i++)
		A[i]=0;
	for(i=1000000;i>=2;i--)
	{
		if(A[i] == 0)
		{
			k = i/2;
			for(j=1;j<=k;j++)
				if(i%j == 0)
					A[j] = 1;

		}
	}*/
	scanf("%d",&test);
	for(u=0;u<test;u++)
	{
		scanf("%d",&n);
		ans = n/2 + n%2;
		printf("%d\n",ans);
	}
	return 0;

}
