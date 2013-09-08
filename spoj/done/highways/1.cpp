#include <cstdio>
#include <vector>
#include <algorithm>
//#include <pair>

using namespace std;

vector< pair< pair<int,int>,int > > v;
int starting[100001]={0},ending[100001]={0},check[100001]={0};

int main()
{
	int i,j,k,l,m,n,t,u,p,cities,num,end,start,from,to,time;
	long long max,ans;

	scanf("%d",&t);
	for(u=0;u<t;u++)
	{
		scanf("%d%d%d%d",&cities,&num,&start,&end);

		for(i=0;i<num;i++)
		{
			scanf("%d%d%d",&from,&to,&time);
			v.push_back(make_pair(make_pair(from,to),time));
			v.push_back(make_pair(make_pair(to,from),time));
		}
		sort(v.begin(),v.end());
			
		starting[v[0].first.first] = 0;
		printf("%d %d %d\n",v[0].first.first,v[0].first.second,v[0].second);
		for(i=1;i<2*num;i++)
		{
			printf("%d %d %d\n",v[i].first.first,v[i].first.second,v[i].second);
			if(v[i-1].first.first != v[i].first.first)
				break;
		}
		if(i < 2*num)
		{
			ending[v[i-1].first.first] = i;
			starting[v[i].first.first] = i;
			i++;
		}
		for(;i<2*num;i++)
		{
			printf("%d %d %d\n",v[i].first.first,v[i].first.second,v[i].second);
			if(v[i-1].first.first != v[i].first.first)
			{
				ending[v[i-1].first.first] = i;
				starting[v[i].first.first] = i;
			}	
		}
		ending[v[i-1].first.first] = i;
		
		for(i=1;i<=cities;i++)
			printf("%d %d\n",starting[i],ending[i]);
		ans = 9223372036854775807;
	/*	for(i=starting[start];i<ending[start];i++)
		{
			check[v[i].first.first] = 1;
			max = func(v[i].first.second,end,0);
			if(max + v[i].second < ans)
				ans = max;
			check[v[i].first.first] = 0;
		}*/
		printf("%lld\n",ans);
		for(i=1;i<=cities;i++)
		{
			starting[i] = ending[i] = 0;
		}
		v.clear();
	}
	return 0;
}
/*
long long func(int start,int end,long long sum)
{
	if(start == end)
		return 0;
	int i,j;
	long long ans = 9223372036854775807,max;
	for(i=starting[start];i<ending[start];i++)
	{
		if(check[v[i].first.first] == 0)
		{
			check[v[i].first.first] == 1;
			max = func(v[i].first.second,end);
			check[v[i].first.first] == 0;
		}
	}
}*/
