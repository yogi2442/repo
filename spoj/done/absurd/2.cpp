#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <cstring>

int main()
{
	char str[11],temp[11],buff[11],ch;
	long long int yogi,len,m;
	long long int i,j,k,l,n,a,b,c,d;
	double p,q;
	long long int test,u,count,last,flag,absurdity,absurdity1;
	
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

		a=p;
		b=q;
		if(p>a)
			a++;

		sprintf(str,"%lld",b);

	//	printf("a = %lld\nb = %lld\n",a,b);
		len = strlen(str);
		flag=0;
		for(i=len-1;i>=0;i--)
		{
			ch = str[i];
			if(ch >= '5')
			{
				str[i] = '5';
				m = atoll(str);
				yogi = m;
				if(m >= a && m <= b && m!=n)
				{
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
						absurdity1 = 2*count - 1;
					else
						absurdity1 = 2*count;
					if(absurdity1 < absurdity)
					{
					//	printf("%lld\n",yogi);
						flag=1;
						break;
					}
				}
			}
			if(ch >= '0')
			{

				str[i] = '0';
				m = atoll(str);
				yogi = m;

				if(m >= a && m <= b && m!=n)
				{
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
						absurdity1 = 2*count - 1;
					else
						absurdity1 = 2*count;
					if(absurdity1 < absurdity)
					{
					//	printf("%lld\n",yogi);
						flag=1;
						break;
					}
				}
			}
			str[i] = '0';
		}

		if(flag == 1)
			printf("absurd\n");
		else
			printf("not absurd\n");
	}
	return 0;
}
