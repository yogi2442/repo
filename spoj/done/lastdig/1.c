#include <stdio.h>
int main()
{
	int test,a,n,m,i;
	long long int b;
	scanf("%d",&test);
	int array[21] = {0};
	int index,ans;
	for(i=0;i<test;i++)
	{
		index = 0;
		scanf("%d%lld",&a,&b);
		if(a == 0)
		{
			printf("0\n");
			continue;
		}
		else if(b == 0)
		{
			printf("1\n");
			continue;
		}
		array[index++] = a % 10;
		n = a * a;
		m = n % 10;
	//	printf("array0 = %d\n",array[0]);
		while(m != array[0])
		{
			array[index++] = m;
			n = n * a;
			m = n % 10;
		}
	//	printf("final index = %d\n",index);
		ans = 0;
		ans = b % index;
		if(ans == 0)
			ans = index;
	//	printf("ans = %d\n",ans);
		printf("%d\n",array[ans-1]);
	}
	return 0;
}
