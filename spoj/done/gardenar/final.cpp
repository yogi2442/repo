#include <cstdio>
#include <cmath>

#define sqr 1.7320508075688772935274463415059 

int main()
{
	int t,u,i,j,k,l,m,n,p,q,r;
	long long ans1,ans2;
	double ans,a,b,c;
	scanf("%d",&t);
	for(u=0;u<t;u++)
	{
		scanf("%d%d%d",&p,&q,&r);
		a = ((p+q+r)*1.0)/2.0;
		b = a*(a-p)*(a-q)*(a-r)*1.0;
	//	c = sqrt(b);
		ans1 = p*p + q*q + r*r;
		ans = (((sqr*ans1*1.0)/4.0)+ 3.0*(sqrt(b)*1.0))/2.0;
		printf("%.2lf\n",ans);
	}
	return 0;
}
