#include <cstdio>
#include <iostream>
#include <cstdlib>

long long merge(int*,int,int);
long long merg(int*,int,int,int);

int n;

int main()
{
	int test,u;
	scanf("%d",&test);
	int *A,i,j,k,l;
	long long ans;
	for(u=0;u<test;u++)
	{
		scanf("%d",&n);
		A = (int*)malloc(sizeof(int)*n);
		for(i=0;i<n;i++)
			scanf("%d",&A[i]);

		ans = merge(A,0,n-1);
		printf("%lld\n",ans);
		free(A);
	}
	return 0;
}

long long merge(int *A, int low,int high)
{
	if(low < high)
	{
		int mid = (low+high)/2;

		long long ans1 = merge(A,low,mid);
		
		ans1 = ans1 + merge(A,mid+1,high);

		ans1 = ans1 + merg(A,low,mid+1,high);

		return ans1;
	}

	return 0;
}

long long merg(int *A,int low,int mid,int high)
{
	int *B = (int*)malloc(sizeof(int)*(high-low+1));

	int i,j,k;
	i = low;
	j = mid;
	k = 0;

	long long count=0;
	while(i <= mid-1 && j <= high)
	{
		if(A[i] <= A[j])
			B[k++] = A[i++];
		else
		{
			B[k++] = A[j++];
			count =  count + (mid-i);
		}
	}
	while(i<=mid-1)
		B[k++] = A[i++];
	while(j<=high)
		B[k++] = A[j++];

	k=0;
	for(i=low;i<=high;i++)
	{
		A[i] = B[k++];
	}
	free(B);
	return count;
}
