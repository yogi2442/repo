#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int A[505][505],parent[505][505];
int func(int,int);

int main()
{
	int i,j,k,l,m,n;
	int t,u,r,c,min,ans;
	scanf("%d",&t);

	for(u=0;u<t;u++)
	{
		min = 1;
		scanf("%d%d",&r,&c);
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
				scanf("%d",&A[i][j]);

		parent[0][0] = -1;
		for(i=1;i<c;i++)
		{
			parent[0][i] = 1;
			A[0][i] = A[0][i-1] + A[0][i];
		}
		for(j=1;j<r;j++)
		{
			parent[j][0] = 0;
			A[j][0] = A[j-1][0] + A[j][0];
		}

		for(i=1;i<r;i++)
		{
			for(j=1;j<c;j++)
			{
				if(A[i][j-1] > A[i-1][j])
				{
					A[i][j] = A[i][j-1] + A[i][j];
					parent[i][j] = 1;
				}
				else
				{
					A[i][j] = A[i-1][j] + A[i][j];
					if(A[i][j-1] == A[i-1][j])
						parent[i][j] = 2;
					else
						parent[i][j] = 0;
				}
			}
		}
	
	/*	for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				printf("%d ",A[i][j]);
			}
			printf("\n");
		}*/
		i = r-1;
		j = c-1;
	//	if(A[i][j] < min)
		//	min = A[i][j];

		ans = func(i,j);
	/*	while(parent[i][j] != -1)
		{
			if(parent[i][j] == 0)
				i--;
			else if(parent[i][j] == 1)
				j--;
			if(A[i][j] < min)
				min = A[i][j];
		}
	*/	
	/*	if(min == 1)
			printf("%d\n",min);
		else
			printf("%d\n",(min*-1)+1);
			*/
		if(ans > 0)
			printf("1\n");
		else
			printf("%d\n",(ans*-1)+1);
	}
	return 0;
}

int func(int i, int j)
{
//	printf("calling func\n");
	int min = A[i][j],min1 = 1,min2 = 1;

	while(parent[i][j] != -1)
	{
		if(A[i][j] < min)
			min = A[i][j];
		
		if(parent[i][j] == 0)
			i--;
		else if(parent[i][j] == 1)
			j--;
		else if(parent[i][j] == 2)
		{
			min1 = func(i,j-1);
			min2 = func(i-1,j);
			break;
		}
	}

	if(min1 > min2)
	{
		if(min < min1)
			return min;
		else
			return min1;
	}
	else
	{
		if(min < min2)
			return min;
		else
			return min2;
	}
	
/*	if(k > 0)
	{
		sort(min1,min1+k);
		if(min1[k-1] > min)
			return min1[k-1];
		else
			return min;
	}
	else
		return min;*/
}
