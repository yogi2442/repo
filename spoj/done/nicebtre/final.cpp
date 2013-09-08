#include <cstdio>
#include <cstring>

char str[12345];
int in;
int func();

int main()
{
	int i,j,k,l,m,n,len,max;
	int t,u,ans;
	scanf("%d",&t);
	for(u=0;u<t;u++)
	{
		scanf("%s",str);
		in=0;
		ans = func();
		printf("%d\n",ans);
	}
	return 0;
}

int func()
{
	if(str[in++] == 'l')
		return 0;
	int ans1,ans2;
	ans1 = func();
	ans2 = func();
	return (ans1 > ans2) ? ans1+1 : ans2+1;
}
