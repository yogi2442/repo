#include <cstdio>

int main()
{
	long long i,j,k,l,m,n,t,u,n3,n5,n15,ans,s3,s5,s15;
	scanf("%lld",&t);
	for(u=0;u<t;u++)
	{
		scanf("%lld",&n);
		ans = 0;
		n3 = n/3;
		if(n3 > 0)
		{
			if(3 + ((n3-1)*3) == n)
				n3--;
			s3 = (n3*(6+(n3-1)*3))/2;
		}
		else
			s3 = 0;
		
		n5 = n/5;
		if(n5 > 0)
		{
			if(5 + ((n5-1)*5) == n)
				n5--;
			s5 = (n5*(10+(n5-1)*5))/2;
		}
		else
			s5 = 0;


		n15 = n/15;;
		if(n15 > 0)
		{
			if(15 + ((n15-1)*15) == n)
				n15--;
			s15 = (n15*(30+(n15-1)*15))/2;
		}
		else
			s15 = 0;

		

		ans = s3 - s15 + s5;
		printf("%lld\n",ans);
	}
	return 0;

}
