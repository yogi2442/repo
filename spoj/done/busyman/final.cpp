#include <cstdio>
#include <iostream>
//#include <pair>
#include <algorithm>

using namespace std;

int main()
{
	int i,count,finish,n,test,u;
	pair<int,int> p[100000];
	scanf("%d",&test);
	for(u=0;u<test;u++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&p[i].second,&p[i].first);
		}
		sort(p,p+n);
		finish = 0;
		count=0;
		for(i=0;i<n;i++)
		{
			if(p[i].second >= finish)
			{
				count++;
				finish = p[i].first;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}

