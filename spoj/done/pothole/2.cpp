#include <cstdio>
#include <cstdlib>

int A[300][300]={0},start[300]={0},end[300]={0},n;

int dfs(int);

int main()
{
	int i,j,k,l,m,t,u,ans,count;
	scanf("%d",&t);
	for(u=0;u<t;u++)
	{
		scanf("%d",&n);
		for(i=1;i<n;i++)
		{
			scanf("%d",&m);
			for(j=0;j<m;j++)
			{
				scanf("%d",&k);
				if(i == 1 || k == n)
					A[i][k] = 1;
				else
				{
					if(i < k)
					{
						A[i][k] = 300;
						A[k][i] = 0;
					}
					else
					{
						A[k][i] = 300;
						A[i][k] = 0;
					}
				}
			}
			A[i][i] = 0;
		}
		
		count=0;
		for(i=2;i<=n;i++)
		{
			if(A[1][i] == 1)
			{
			//	printf("yogi\n");
				ans = dfs(i);
				if(ans == 1)
				{
					count++;
					A[1][i]--;
					A[i][1]++;
				}
				for(j=1;j<=n;j++)
					start[j] = 0;
			}
		}
		printf("%d\n",count);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				A[i][j] = 0;
			start[i] = 0;
		}
	}
	return 0;
}

int dfs(int i)
{
//	printf("%d ",i);
	if(i == n)
	{
		return 1;
	}
	int j,k,l;
	for(j=2;j<=n;j++)
	{
		if(A[i][j] > 0)
		{
			if(start[j] == 0)
			{
				start[j] = 1;
				if(dfs(j) == 1)
				{

					A[i][j]--;
					A[j][i]++;
					return 1;
				}
			}
		}
	}
	return 0;
}




