#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;
long long array[1000001],array1[1000001];
void func()
{
	int i,j;
	for(i=1;i<=1000000;i++)
	{
		array[i] = i;
	}
	for(i=2;i<=1000000;i++)
	{
		if(array[i] == i)
		{
			for(j=2*i;j<=1000000;j=j+i)
			{
				array[j] = array[j] - array[j]/i;
			}
		}
		if(array[i-1] == i-1)
			array[i-1] = i-2;
	}



	array[1] = 1;

	for(i=1;i<=1000000;i++)
	{
		for(j=i;j<=1000000;j=j+i)
		{
			array1[j] = array1[j] + i*array[i];
		}
	}
	
}

int main()
{
	int i,k,n;
	long long ans1;

	func();
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d",&n);
		ans1 = ((1+array1[n])*n)/2;
		printf("%lld\n",ans1);
	}
	return 0;


}
