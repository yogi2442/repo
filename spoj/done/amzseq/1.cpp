#include <cstdio>
#include <iostream>

int main()
{
	long long test,u,i,j;
	long long zero[30],one[30],two[30];
	zero[1] = 1;
	one[1] = 1;
	two[1] = 1;

	zero[0] = 0;
	one[0] = 0;
	two[0] = 1;
	for(i=2;i<30;i++)
	{
		zero[i] = zero[i-1] + one[i-1];
		one[i] = zero[i-1] + one[i-1] + two[i-1];
		two[i] = one[i-1] + two[i-1];
	}
//	scanf("%lld",&test);
//	for(u=0;u<test;u++)
//	{
		scanf("%lld",&i);

		j = zero[i]+one[i]+two[i];
		printf("%lld\n",j);
//	}
	return 0;
}
