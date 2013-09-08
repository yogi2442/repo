#include <cstdio>
#include <iostream>
#include <cmath>

int main()
{
	long long i,j,k,l,m,n,a,b,p,q,count;
	scanf("%lld",&n);
	while(n != 0)
	{
		m = sqrt(n);
		if(n == 1)
		{
			printf("2^0\n");
			scanf("%lld",&n);
			continue;
		}
		count=0;
		while(n % 2 == 0 && n != 1)
		{
			n = n / 2;
			count++;
		}
		if(count && n != 1)
			printf("2^%lld ",count);
		else if(count && n == 1)
			printf("2^%lld\n",count);
		count=0;
		while(n % 3 == 0 && n != 1)
		{
			n = n /3;
			count++;
		}
		if(count && n!=1)
			printf("3^%lld ",count);
		else if(count && n == 1)
			printf("3^%lld\n",count);

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
				printf("%lld^%lld ",p,count);
			else if(count && n == 1)
				printf("%lld^%lld\n",p,count);
			count = 0;
			while(n % q == 0)
			{
				n = n / q;
				count++;
			}
			if(count && n!=1)
				printf("%lld^%lld ",q,count);
			else if(count && n == 1)
				printf("%lld^%lld\n",q,count);
			j++;
			p = 6*j - 1;
			q = 6*j + 1;

		}
		if(n > 1)
			printf("%lld^1\n",n);
		scanf("%lld",&n);
	}

}
