#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	long long t,u,n,p,q,r,s,a,d,m1,m2,temp1,temp2,i,m3,n1,n2,a1,d1;

	scanf("%lld",&t);

	for(u=0;u<t;u++)
	{
		scanf("%lld%lld%lld",&p,&q,&s);

		temp1 = (7*p + 5*q + 2*s);
		temp2 = sqrt((temp1*temp1) - 48*s*(p+q));

	//	printf("temp1 = %lld temp2 = %lld\n",temp1,temp2);
		m1 = (temp1 - temp2);
		m2 = (temp1 + temp2);
		m3 = 2*(p+q);
		//	printf("m1 = %lld m2 = %lld\n",m1,m2);
		n1 = m1 / m3;
		n2 = m2 / m3;

		if(n1 >= 7)
		{
			d1 = (p-q)/(6-n1);
			a1 = p - 2*d1;
			if(a1 + 2*d1 == p && a1 + (n1-4)*d1 == q && n1*(p+q+d1) == 2*s)
			{
				n = n1;
				a = a1;
				d = d1;
			}
		}
		if(n2 >= 7)
		{
			d1 = (p-q)/(6-n2);
			a1 = p - 2*d1;
			if(a1 + 2*d1 == p && a1 + (n2-4)*d1 == q && n2*(p+q+d1) == 2*s)
			{
				n = n2;
				a = a1;
				d = d1;
			}
		}

	//	printf("d = %lld\n",d);

	//	printf("a = %lld\n",a);

		printf("%lld\n",n);
		for(i=0;i<n;i++)
		{
			if(i == n-1)
				printf("%lld\n",a+ i*d);
			else
				printf("%lld ",a+ i*d);
		}
	}
	return 0;
}
