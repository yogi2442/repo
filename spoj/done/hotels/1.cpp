#include <cstdio>
#include <cstdlib>

int main()
{
	long long i,j,k,l,m,n,*A,sum,max;
	scanf("%lld%lld",&n,&m);

	A = (long long*)malloc(sizeof(long long)*n);
	sum =0;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		sum = sum + k;
		A[i] = sum;
	}

	i=0;j=0;
	sum=0;
	max=0;
	while(i < n && j < n)
	{
		if(A[j] - A[i] <= m)
		{
			if(A[j] - A[i] > max)
				max = A[j] - A[i];
			j++;
		}
		else if(A[j] - A[i] > m)
			i++;
	}
	printf("%lld\n",max);
	return 0;
}
