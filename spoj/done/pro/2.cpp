#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
	int i,j,k,l,n,m,u,t,siz,*A[5001],start[5001]={0},end[5001],count[5001],min,max;
	long long ans = 0;
	scanf("%d",&t);
	siz = 0;
	for(u=0;u<t;u++)
	{
		scanf("%d",&end[u]);
		A[u] = new int[end[u]];
		count[u] = end[u];
		for(i=0;i<end[u];i++)
		{
			scanf("%d",&A[u][i]);
		}
		sort(A[u],A[u]+end[u]);
		end[u]--;
	}
	min = 0;
	max = 0;
	for(u=0;u<t;u++)
	{
		for(i=0;i<=u;i++)
		{
			if(count[i] > 0)
			{
				if(A[i][start[i]] < A[min][start[min]])
					min = i;
				if(A[i][end[i]] > A[max][end[max]])
					max = i;
			}
		}
		count[min]--;
		count[max]--;

			
		printf("%d\n",A[max][end[max]] - A[min][start[min]]);
		ans += A[max][end[max]] - A[min][start[min]];
		
		start[min]++;
		end[max]--;

	}
	printf("%lld\n",ans);
	return 0;
}

