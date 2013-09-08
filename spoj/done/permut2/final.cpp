#include <cstdio>
#include <iostream>
#include <cstdlib>

int main()
{
	int n,*A,*B,i;
	scanf("%d",&n);
	while(n != 0)
	{
		A = (int*)malloc(sizeof(int)*(n+1));
		B = (int*)malloc(sizeof(int)*(n+1));
		for(i=1;i<=n;i++)
		{
			scanf("%d",&A[i]);
		}
		for(i=1;i<=n;i++)
		{
			B[A[i]] = i;
		}
		for(i=1;i<=n;i++)
		{
			if(A[i] != B[i])
				break;
		}
		if(i == n+1)
			printf("ambiguous\n");
		else
			printf("not ambiguous\n");
		scanf("%d",&n);
		free(A);
		free(B);
	}
	return 0;
}
