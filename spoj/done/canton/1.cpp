#include <cstdio>

int main()
{
	int i,j,k,l,m,n,test,u,r,c,flag;
	scanf("%d",&test);
	for(u=0;u<test;u++)
	{
		scanf("%d",&n);
		m = n;
		flag=1;
		r=1;
		c=1;
		n--;
		while(n)
		{
			if(r == 1 && flag == 1)
			{
				c++;
				flag=0;
			}
			else if(c == 1 && flag == 0)
			{
				r++;
				flag=1;
			}
			else if(flag == 0)
			{
				// upar di nicho;
				r++;
				c--;
			}
			else if(flag == 1)
			{
				// nicho di upar;
				r--;
				c++;
			}
			n--;
		}
		printf("TERM %d IS %d/%d\n",m,r,c);
	}
	return 0;
}
