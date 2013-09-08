#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
	int i,j,k,l,m,n,*A;
	scanf("%d%d",&n,&k);
	A = (int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	sort(A,A+n);
	int count=0;
	i=0;j=0;
	while(i < n && j < n)
	{
		if(i == j)
			j++;
		if(A[j] - A[i] < k)
			j++;
		else if(A[j] - A[i] > k)
			i++;
		else if(A[j] - A[i] == k)
		{
			count++;
			j++;
		}
	}
	printf("%d\n",count);
	return 0;

}
