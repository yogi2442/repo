#include <cstdio>

int main()
{
	unsigned long long i,j,k,n,cards,items,yogi,hey;
	int test,u;
	yogi = 18446744073709551616/2;
	int A[30];
	scanf("%d",&test);
	for(u=0;u<test;u++)
	{
		for(i=0;i<30;i++)
			A[i]=0;
		scanf("%lld%lld",&n,&k);
		i=29;
		while(n > 0)
		{
			A[i--] = n % 10;
			n = n / 10;
		}

	//	items = n;
	//	cards = n;
		j = 1;
		hey = 0;
		while(j > 0)
		{
			j = cards/k;
			hey = hey + j;
			if(hey >= yogi )
			{

			}
			cards = j + (cards % k);
		}
		printf("%lld\n",items);
	}
	return 0;
}
