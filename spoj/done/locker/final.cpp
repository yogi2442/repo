#include <cstdio>
#include <cmath>

long long A[21];
long long mod = 1000000007;

long long func(long long,long long);

int main()
{
	long long i,j,k,l,m,n,t,u,count2,count3;
//	A[0] =1;
//	for(i=1;i<21;i++)
//		A[i] = A[i-1]*3;
//	printf("%lld\n",func(3,15));
	scanf("%lld",&t);
	for(u=0;u<t;u++)
	{
		scanf("%lld",&n);
		count2=0;
		if(n <= 4)
			printf("%lld\n",n);
		else
		{
			count3 = n/3;
			if(n%3 == 1)
			{
				count3--;
				count2 = 4;
			}
			else if(n%3 == 2)
				count2=2;
			else
				count2=1;

			printf("%lld\n",(func(3,count3) * count2)%1000000007);
		}
	}
	return 0;
}

long long func(long long number, long long power)
{
	if(power <= 2)
	{
		long long newNumber=1;
		while(power)
		{
			newNumber = newNumber * number;
			power--;
		}
		return newNumber % mod;
	}
	long long nextNumber=1,count=0,nextPower,reminder,ret,presentNumber;
	while(nextNumber < mod)
	{
		nextNumber = nextNumber * number;
		count++;
	}
	nextNumber = nextNumber % mod;

	nextPower = power / count;

	reminder = power % count;

//	printf("nextnumber  = %lld count = %lld next power = %lld reminder = %lld\n",nextNumber,count,nextPower,reminder);	
	ret = func(nextNumber,nextPower);

	presentNumber = 1;
	while(reminder)
	{
		presentNumber = presentNumber * number;
		reminder--;
	}

	return (presentNumber*ret) % mod;
}

