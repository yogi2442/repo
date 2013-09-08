#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define inf 4294967295

vector< pair<int,int> > v[100001];

priority_queue< pair<int,int> , vector< pair<int,int> > ,greater< pair<int,int> > > q;  

long long dist[100001];
int visit[100001];

int main()
{
	int i,j,k,l,m,n,t,u,p,cities,num,end,start,from,to,time,distance,ind,siz;
	
	scanf("%d",&t);
	for(u=0;u<t;u++)
	{
		scanf("%d%d%d%d",&cities,&num,&start,&end);
		for(i=1;i<=cities;i++)
		{
			dist[i] = inf;
			v[i].clear();
			visit[i] = 0;
		}

		for(i=0;i<num;i++)
		{
			scanf("%d%d%d",&from,&to,&time);
			v[from].push_back(make_pair(time,to));
			v[to].push_back(make_pair(time,from));
		}
		dist[start] = 0;
		q.push(make_pair(dist[start],start));
		
		while(!q.empty())
		{
			distance = dist[q.top().second];
			ind = q.top().second;
			q.pop();
			//	printf("distance = %lld ind = %d\n",distance,ind);
			if(visit[ind] == 0)
			{
				visit[ind] = 1;
				siz = v[ind].size();
				//	printf("siz = %d\n",siz);
				for(i=0;i<siz;i++)
				{
					if(visit[v[ind][i].second] == 0)
					{
						//	printf("dist[v[%d][%d].second] = %lld ",ind,i,dist[v[ind][i].second]);
						if(dist[v[ind][i].second] > distance + v[ind][i].first)
						{
							dist[v[ind][i].second] = distance + v[ind][i].first;
							q.push(make_pair(dist[v[ind][i].second],v[ind][i].second));
						}
						//	printf("v[%d][%d].second = %d ",ind,i,v[ind][i].second);
						//	printf("v[%d][%d].first = %d  dist[v[%d][%d].second] = %lld\n",ind,i,v[ind][i].first,ind,i,dist[v[ind][i].second]);
					}
				}
			}
		}
		if(dist[end] == inf)
			printf("NONE\n");
		else
			printf("%lld\n",dist[end]);
	}
	return 0;
}
