#include <cstdio>
#include <cstdlib>

int A[300][300]={0},start[300]={0},end[300]={0},n;

int dfs(int);

int main()
{
	int i,j,k,l,m,t,u,count,ans;
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
				A[i][k] = 1;
				A[k][i] = 1;
			}
		}
		for(i=1;i<=n;i++)
		{
			if(A[n][i] == 1)
				end[i] = 1;
		}
		printf("starting pos: ");
		for(i=1;i<=n;i++)
			if(start[i] == 1)
				printf("%d ",i);
		printf("\nending pos: ");
		for(i=1;i<=n;i++)
			if(end[i] == 1)
				printf("%d ",i);
		printf("\n");
	
		count=0;
		if(end[1] == 1)
		{
			count++;
			end[1] = 0;
		}
		for(i=2;i<=n;i++)
		{
			if(A[1][i] == 1)
			{
				printf("%d ",i);
				ans = dfs(i);
				if(ans == 1)
					count++;
				printf("\n");
			}
		}
		printf("%d\n",count);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				A[i][j] = 0;
			end[i]=0;
		}
	//	printf("count = %d\n",count);
	}
	return 0;
}

int dfs(int i)
{
	printf("i = %d ",i);
	if(end[i] == 1)
	{
		end[i] = 0;
		printf("found ");
		return 1;
	}
	int j,k,l;
	for(j=i+1;j<n;j++)
	{
		if(A[i][j] == 1)
		{
			printf("%d ",j);
			if(dfs(j) == 1)
				return 1;
		}
	}
	return 0;
}




