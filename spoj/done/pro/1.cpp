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
/*	printf("\n");
	for(l=0;l<t;l++)
	{
		for(m=start[l];m<count[l];m++)
			printf("%d ",A[l][m]);
		printf("\n");
	}*/
	for(u=0;u<t;u++)
	{
	/*	for(l=0;l<t;l++)
		{
			for(m=start[l];m<=end[l];m++)
				printf("%d ",A[l][m]);
			printf("\n");
		}*/
		min = -1;
		max = -1;
		if(min == -1)
		{
			for(i=0;i<=u;i++)
			{
				if(count[i] > 0)
				{
					min = i;
					max = i;
					break;
				}
			}
		}
		i++;
		for(j=i;j<=u;j++)
		{
			if(A[j][start[j]] <= A[min][start[min]] && count[j] > 0)
			{
				min = j;
				if(A[j][end[j]] > A[max][end[max]] && count[j] > 0)
					max = j;
				break;
			}
			if(A[j][end[j]] >= A[max][end[max]] && count[j] > 0)
			{
				max = j;
				if(A[j][start[j]] < A[min][start[min]] && count[j] > 0)
					min = j;
				break;
			}
		}

		for(i=j+1;i<=u;i++)
		{
			if(A[i][start[i]] < A[min][start[min]] && count[i] > 0 && i > min)
				min = i;
			if(A[i][end[i]] > A[max][end[max]] && count[i] > 0 && i > max)
				max = i;
		}
		count[min]--;
		count[max]--;


	//	printf("max = %d min = %d\n",A[max][end[max]],A[min][start[min]]);
		ans += A[max][end[max]] - A[min][start[min]];

		start[min]++;
		end[max]--;
	//	printf("\n");

	}
	printf("%lld\n",ans);
	return 0;
}

