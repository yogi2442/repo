#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()
{
	long long i,j,k,l,m,n,*A,test,u;
	scanf("%lld",&test);
	for(u=0;u<test;u++)
	{
		scanf("%lld%lld",&n,&k);
		A = (long long*)malloc(sizeof(long long)*n);
		for(i=0;i<n;i++)
			scanf("%lld",&A[i]);
		sort(A,A+n);
		i=0;
		j=k-1;
		m = 1000000000;
		while(j < n)
		{
			if(m > A[j] - A[i])
				m = A[j] - A[i];
			i++;
			j++;
		}
		printf("%lld\n",m);
		free(A);
	}
	return 0;
}
