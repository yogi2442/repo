#include <cstdio>
int main()
{
	long long i,j,m,n;
	scanf("%lld",&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&j,&n);
		if(n)
			printf("Pagfloyd wins.\n");
		else
			printf("Airborne wins.\n");
	}
	return 0;
}
