#include <cstdio>
#include <iostream>
#include <cmath>

int main()
{
	long long i,j,k,l,m,n,a,b,p,q,count,etf,n1;
//	scanf("%lld",&n);
	n1 = 100000001;
	while(n1 < 1000000000000)
	{
		n = n1;
		etf = n1;
		m = sqrt(n);
		count=0;
		while(n % 2 == 0 && n != 1)
		{
			n = n / 2;
			count++;
		}
		if(count && n != 1)
		{
		//	printf("2^%lld ",count);
			etf -= etf / 2;
		}
		else if(count && n == 1)
		{
		//	printf("2^%lld\n",count);
			etf -= etf / 2;
		}
		count=0;
		while(n % 3 == 0 && n != 1)
		{
			n = n /3;
			count++;
		}
		if(count && n!=1)
		{
		//	printf("3^%lld ",count);
			etf -= etf / 3;
		}
		else if(count && n == 1)
		{
		//	printf("3^%lld\n",count);
			etf -= etf / 3;
		}

		j=1;
		p = 6*j - 1;
		q = 6*j + 1;
		while(n != 1 && p <= m && q <= m)
		{
			count=0;
			while(n % p == 0)
			{
				n = n / p;
				count++;
			}
			if(count && n!=1)
			{
			//	printf("%lld^%lld ",p,count);
				etf -= etf / p;
			}
			else if(count && n == 1)
			{
			//	printf("%lld^%lld\n",p,count);
				etf -= etf / p;
			}
			count = 0;
			while(n % q == 0)
			{
				n = n / q;
				count++;
			}
			if(count && n!=1)
			{
			//	printf("%lld^%lld ",q,count);
				etf -= etf / q;
			}
			else if(count && n == 1)
			{
			//	printf("%lld^%lld\n",q,count);
				etf -= etf / q;
			}
			j++;
			p = 6*j - 1;
			q = 6*j + 1;

		}
		if(n > 1)
		{
		//	printf("%lld^1\n",n);
			etf -= etf / n;
		}

		printf("%lld %lld\n",n1,etf);
		n1++;
	//	scanf("%lld",&n);
		
	}
	return 0;

}
