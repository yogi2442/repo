#include <cstdio>
#include <iostream>
#include <cstdlib>

int main()
{
	float n,m;
	int cards,i;
	scanf("%f",&n);
	while(n != 0.00)
	{
	//	printf("%f\n",n);
		if(n <= 0.5000000)
		{
			printf("1 card(s)\n");
			scanf("%f",&n);
			continue;
		}
		m = 0.000000;
		i=2;
		while(m < n)
		{
			m = m + (1.0/i);
			i++;
		//	printf("m = %f\n",m);
		}
		printf("%d card(s)\n",i-2);

		scanf("%f",&n);
	}
	return 0;
}

