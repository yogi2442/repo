#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
	long long i,j,k,l,m,n,test,u,*A;
	scanf("%lld",&test);
	char str[1000];
	for(u=0;u<test;u++)
	{
		scanf("%lld",&n);
		A = (long long*)malloc(sizeof(long long)*n);
		for(i=0;i<n;i++)
		{
			scanf("%s%lld",str,&A[i]);
		}
		sort(A,A+n);
		
		m=0;
		for(i=0;i<n;i++)
		{
			m = m + abs(A[i] - i - 1);
		}
		printf("%lld\n",m);
	}
	return 0;
}
