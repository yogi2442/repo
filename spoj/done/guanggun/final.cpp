#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	unsigned long long n,ans,p,q,r;	
	while(scanf("%llu",&n) != EOF)
	{
		if(n == 0)
		{
			printf("0\n");
			continue;
		}
	//	printf("%lld\n",n);
		p = (n)/9;
		q = n % 9;
		ans = (81*p) + q*q;
		printf("%llu\n",ans);
	}
	return 0;
}
