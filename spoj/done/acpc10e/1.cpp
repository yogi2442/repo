#include <cstdio>
#include <iostream>

int main()
{
	long long i,j,k,l,m,n,a,b,c,d;
	long long A[40],p,q,r,s;
	A[0] = 1;
	for(i=1;i<40;i++)
	{
		A[i] = A[i-1] * 2;
	}
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	while(a != -1 && b != -1 && c != -1 && d != -1)
	{
		p = (a*c)+d;
		for(i=0;i<40;i++)
		{
			if(A[i] >= p)
				break;
		}
		q = A[i]-1;
	//	printf("q = %lld\n",q);
		r = a*b*(b-1)/2;
	//	printf("r = %lld\n",r);
		r = a*b*(b-1)/2;
		s = q+r;
	//	printf("matches = %lld\n",s);
	//	printf("required teams = %lld\n",A[i]-p);
		printf("%lld*%lld/%lld+%lld=%lld+%lld\n",a,c,b,d,s,A[i]-p);
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	}
	return 0;
}
