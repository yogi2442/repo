#include <cstdio>
#include <iostream>
#include <cstdlib>


int main()
{
	int test,u,i,j,k;
	long long n,m,ans,p,q,*A;
//	A = (long long*)malloc(sizeof(long long)*1000001);
//	for(i=1;i<=1000000;i++)
//		A[i] = ((i)*(i+1))/2;
	scanf("%lld",&test);
	for(u=0;u<test;u++)
	{
		scanf("%lld",&n);
		m = n-1;
		ans = n*n + (((m)*(m+1)*((2*m)+1))/6 + ((m)*(m+1))/2)/2;
	//	for(m=n-1;m>0;m--)
	//	{
	//	//	ans = ans + ((m)*(m+1))/2;
	//		ans = ans + A[m];
	//	}
		m = n/2;
		for(i=2;i<=m;i++)
		{
			p = (n+1) - (2*i);
			ans = ans + ((p)*(p+1))/2;	
		}
		printf("%lld\n",ans);
	}
	return 0;

}
