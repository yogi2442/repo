#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>

int main()
{
	long long int A[33000],i,j,k,l,m,n,m1,prime[3900];
	m = sqrt(1000000000);
	
	for(i=0;i<33000;i++)
		A[i] = 1;

	m1 = sqrt(m);
	for(i=2;i<33000;i++)
	{
		if(A[i] == 1)
		{	
			for(j=i;j*i<33000;j++)
			{
				A[j*i] = 0;
			}
		}
	}

	l = 0;
	for(i=2;i<33000;i++)
	{
		if(A[i] == 1)
		{
			prime[l++] = i;
		//	if(i < 31000)
		//		printf("%lld\n",i);
		}
	}
//	exit(0);
//	printf("\nl = %d\n",l);

	long long int test,u,a,b,flag;
	scanf("%lld",&test);
	
	for(u=0;u<test;u++)
	{
		scanf("%lld%lld",&a,&b);
		for(i=a;i<=b;i++)
		{
			flag = 0;
			if(i == 1)
				continue;
			else if(i==2 || i==3)
				printf("%lld\n",i);
			else
			{
				m = sqrt(i);
				for(j=0;j<=m;j++)
				{
					if(prime[j] <= m)
					{
						if(i % prime[j] == 0)
							break;
					}
					else
					{
						flag=1;
						break;
					}
				}
			}
			if(flag == 1)
				printf("%lld\n",i);
		}
	//	if(u != test-1)
	//		printf("\n");
	}

	return 0;
}
