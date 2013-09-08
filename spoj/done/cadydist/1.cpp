#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()
{
	long long *A,*B,i,j,n;
	long long ans,ans1;
	scanf("%lld",&n);
	while(n > 0)
	{
		A = (long long*)malloc(sizeof(long long)*n);
		B = (long long*)malloc(sizeof(long long)*n);

		for(i=0;i<n;i++)
			scanf("%lld",&A[i]);
		for(i=0;i<n;i++)
			scanf("%lld",&B[i]);

		sort(A,A+n);
		sort(B,B+n);

		i=0;j=n-1;
		ans=0;
		while(i < n && j >= 0)
		{
			ans1 = A[i++]*B[j--];
			ans = ans + ans1;
		}
		printf("%lld\n",ans);
		free(A);
		free(B);
		scanf("%lld",&n);
	}
	return 0;
}
