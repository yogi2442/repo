#include <cstdio>

int main()
{
	int i,n,ans=1,flag;
	int p=0,q=0,r=0;
	char str[10];
	flag=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",str);
		if(str[0] == '1' && str[2] == '4')
		{
			p++;
		}
		else if(str[0] == '1' && str[2] == '2')
		{
			q++;
		}
		else if(str[0] == '3' && str[2] == '4')
		{
			r++;
		}
	}
	ans += r ;
	p -= r;
	if(p<0)
		p=0;

	ans += q/2;
	if(q%2 == 1)
	{
		ans++;
		p = p - 2;
	}
	if(p<0)
		p=0;

	if(p > 0)
	{
		p = p + 3;
		ans += p/4;
	}
	printf("%d\n",ans);
	return 0;
}
