#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int func(int*,int,int,int);

int main()
{
	int *A,n,i,j,k,l,test,u,left,right,mid,m,ans;
	scanf("%d",&test);
	for(u=0;u<test;u++)
	{
		scanf("%d%d",&n,&m);
		A = (int*)malloc(sizeof(int)*n);

		for(i=0;i<n;i++)
			scanf("%d",&A[i]);

		sort(A,A+n);
		left = 0;
		right = A[n-1];

		while(left <= right)
		{
			mid = (left+right)/2;
			ans = func(A,n,mid,m);
			if(ans == 1)
				left = mid+1;
			else
				right = mid-1;
		}
		printf("%d\n",left-1);
		free(A);
	}
	return 0;
}

int func(int *A, int n, int dist, int cow)
{
	int prev = A[0],i;
	cow--;
	for(i=0;i<n;i++)
	{
		if(A[i]-prev >= dist)
		{
			cow--;
			prev = A[i];
		}
	}
	if(cow <= 0)
		return 1;
	else
		return 0;
}
