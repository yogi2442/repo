#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	long double p,q,r,a,b,c,ans,area,ra,koi;
	int i,j,t,u;
	scanf("%d",&t);
	for(u=0;u<t;u++)
	{
		scanf("%Lf%Lf%Lf%Lf",&a,&p,&q,&r);
		
		area = 1.5*a*p;
		b = (2.0/3.0)*area/q;
		c = (2.0/3.0)*area/r;
		
		ra = (a*b*c*1.0)/(4.0*area);
		koi = 9.0*ra*ra-((a*a*1.0)+(b*b*1.0)+(c*c*1.0));
	//	printf("%Lf\n",koi);
		if(koi <= 0.0)
			ans = 0.0;
		else
			ans =((2.0)*pow(9.0*ra*ra-((a*a*1.0)+(b*b*1.0)+(c*c*1.0)),0.5))/3.0;

		printf("%.3Lf %.3Lf\n",area,ans);
	}
	return 0;
}
