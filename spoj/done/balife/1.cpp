#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>

int main()
{
	long long int i,j,k,l,m,n,max;
	long long int A[9001];
	scanf("%lld",&n);
	while(n != -1)
	{
		max = 0;
		scanf("%lld",&A[0]);
		for(i=1;i<n;i++)
		{
			scanf("%lld",&m);
			A[i] = A[i-1]+m;
		}
		if(A[n-1] % n != 0)
		{
			printf("-1\n");
		}
		else
		{
			m = A[n-1]/n;
			for(i=0;i<n;i++)
			{
				l = A[i] - (m*(i+1));
				k = abs(l);
				if(k > max)
					max = k;
			}
			printf("%lld\n",max);
		}
		scanf("%lld",&n);
	}
	return 0;
}
