#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()
{
	int i,j,k,l,m,n,*A,ans;
	scanf("%d",&n);
	while(n != 0)
	{
		A = (int*)malloc(sizeof(int)*n);
		for(i=0;i<n;i++)
			scanf("%d",&A[i]);
		sort(A,A+n);
		ans=0;
		for(i=0;i<n;i++)
		{
			if(n-i <= A[i])
		//	if(A[i] >= i && ans < n-i && A[i] >= n-i)
			{
				ans = n-i;
				break;
			}
		}
		printf("%d\n",ans);
		scanf("%d",&n);
		free(A);
	}
	return 0;
}
