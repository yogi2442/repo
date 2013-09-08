#include <stdio.h>
int main()
{
	int n,m;
	scanf("%d",&n);
	while(n!=0)
	{
		m = ((n)*(n+1)*((2*n)+1))/6;
		printf("%d\n",m);
		scanf("%d",&n);
	}
	return 0;
}
