#include <cstdio>
#include <cstdlib>

int main()
{
	long long i,j,k,l,m,n,test,u,*A,*yes,*no;
	scanf("%lld",&test);
	for(u=0;u<test;u++)
	{
		scanf("%lld",&n);
		if(n == 0)
		{
			printf("Case %lld: 0\n",u+1);
			continue;
		}
		A = (long long*)malloc(sizeof(long long)*n);
		yes = (long long*)malloc(sizeof(long long)*n);
		no = (long long*)malloc(sizeof(long long)*n);
		
		for(i=0;i<n;i++)
			scanf("%lld",&A[i]);
		yes[0] = A[0];
		no[0] = 0;

		for(i=1;i<n;i++)
		{
			yes[i] = no[i-1]+A[i];

			if(yes[i-1] > no[i-1])
				no[i] = yes[i-1];
			else
				no[i] = no[i-1];
		}
		if(yes[n-1] > no[n-1])
			printf("Case %lld: %lld\n",u+1,yes[n-1]);
		else
			printf("Case %lld: %lld\n",u+1,no[n-1]);
		free(A);
		free(yes);
		free(no);
	}
	return 0;
}
