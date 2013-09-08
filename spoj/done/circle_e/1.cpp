#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	long long  i,j,k,l,p,q,r,n;
	double ans;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld%lld",&p,&q,&r);
		ans = (p*q*1.0)/((p*q)*1.0+(q*r)*1.0+(p*r)*1.0+(2.0*((pow(p*1.0,0.5)*pow(q*1.0,0.5)*pow(r*1.0,0.5)*pow((p+q+r)*1.0,0.5)))));
		ans = ans*r*1.0;
		printf("%lf\n",ans);
	}
	return 0;

}
