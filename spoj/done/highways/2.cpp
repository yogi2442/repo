#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
//#include <pair>

using namespace std;

#define inf 4294967295

vector< pair<int,int> > v[100001];
//vector < pair<int,int> > q;
/*
bool myfunc()(pair<int,int>&a ,pair<int,int>&b)
{
	if(a.first < b.first)
		return true;
	else if(a.first >= b.first)
		return false;
}*/
priority_queue< pair<int,int> , vector< pair<int,int> > ,less< pair<int,int> > > q;  


long long dist[100001];
int visit[100001] = {0},inQ[100001] = {0};

int main()
{
	int i,j,k,l,m,n,t,u,p,cities,num,end,start,from,to,time,distance,ind,siz,yogi;
	long long max,ans;


	scanf("%d",&t);
	for(u=0;u<t;u++)
	{
		scanf("%d%d%d%d",&cities,&num,&start,&end);

		for(i=0;i<num;i++)
		{
			scanf("%d%d%d",&from,&to,&time);
			v[from].push_back(make_pair(time,to));
			v[to].push_back(make_pair(time,from));
		}
		for(i=1;i<=cities;i++)
		{
		//	sort(v[i].begin(),v[i].end());
			dist[i] = inf;
		}
		dist[start] = 0;
		q.push(make_pair(dist[start],start));
		
	//	yogi = 0;
		while(!q.empty())
		{
		//	sort(q.begin()+yogi,q.end());
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
						/*	if(inQ[v[ind][i].second] == 0)
							{
							q.push_back(make_pair(dist[v[ind][i].second],v[ind][i].second));
							inQ[v[ind][i].second] = 1;
							}*/
						//	printf("v[%d][%d].second = %d ",ind,i,v[ind][i].second);
						//	printf("v[%d][%d].first = %d  dist[v[%d][%d].second] = %lld\n",ind,i,v[ind][i].first,ind,i,dist[v[ind][i].second]);
					}
				}
			}
			//	yogi++;
		}
		if(dist[end] == inf)
			printf("NONE\n");
		else
			printf("%lld\n",dist[end]);


		for(i=1;i<=cities;i++)
		{
			v[i].clear();
		//	inQ[i] = 0;
			dist[i] = inf;
			visit[i] = 0;
		}
	//	q.clear();
	}
	return 0;
}
