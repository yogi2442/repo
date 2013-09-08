#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <cstring>

int main()
{
	int *ab;
	ab = (int*)malloc(sizeof(int)*210000001);
	memset(ab,0,210000001);
//	int ab[210000001]={};
	long long i,j,k,l,m,n,a,b,c,d;
	double p,q;
	long long test,u,count,last,flag,absurdity,absurdity1;
	scanf("%lld",&test);
	for(u=0;u<test;u++)
	{
		scanf("%lld",&n);
		m = n;
		count=0;
		while(m>0)
		{
			if(m%10 != 0)
			{
				last = m%10;
				m = m/10;
				count++;
				break;
			}
			m = m/10;
		}
		while(m>0)
		{
			m = m/10;
			count++;
		}
		if(last == 5)
			absurdity = 2*count - 1;
		else
			absurdity = 2*count;
	//	printf("absurdity = %lld\n",absurdity);

		p = n*1.0*0.95;
		q = n*1.0*1.05;

		n = n - n%5;
		i = 0;
		a = n - 5*i;
		b = n + 5*i;
		flag=0;
		while(a >= p || b <= q)
		{
			if(ab[a/5] != 0)
			{	
				if(absurdity > ab[a/5])
				{
					flag = 1;
					break;
				}
			}
		//	printf("a = %lld\n",a);
		//	printf("b = %lld\n",b);
			else if(a >= p && a <= q)
			{
				c = a;
			//	printf("a = %lld\n",a);
				count=0;
				while(a>0)
				{
					if(a%10 != 0)
					{
						last = a%10;
						a = a/10;
						count++;
						break;
					}
					a = a/10;
				}
				while(a>0)
				{
					a = a/10;
					count++;
				}
				if(last == 5)
					absurdity1 = 2*count - 1;
				else
					absurdity1 = 2*count;
				ab[c/5] = absurdity1;
			//	printf("%lld\n",absurdity1);
				if(absurdity1 < absurdity)
				{
					flag = 1;
					break;
				}

			}
			if(ab[b/5] != 0)
			{
				if(ab[b/5] < absurdity)
				{
					flag = 1;
					break;
				}
			}
			else if(b <= q && b >= p)
			{
			//	printf("b = %lld\n",b);
				d = b;
				count=0;
				while(b>0)
				{
					if(b%10 != 0)
					{
						last = b%10;
						b = b/10;
						count++;
						break;
					}
					b = b/10;
				}
				while(b>0)
				{
					b = b/10;
					count++;
				}
				if(last == 5)
					absurdity1 = 2*count - 1;
				else
					absurdity1 = 2*count;
			//	printf("%lld\n",absurdity1);
				ab[d/5] = absurdity1;
				if(absurdity1 < absurdity)
				{
					flag = 1;
					break;
				}
			}
			i++;
			a = n - 5*i;
			b = n + 5*i;
		}
		if(flag == 1)
			printf("absurd\n");
		else
			printf("not absurd\n");
	}
	return 0;
}
