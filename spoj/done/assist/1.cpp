#include <cstdio>

int main()
{
	int m = 40000;
	int i,j,k,l,n,A[40000] = {0},B[3000];

	n=0;
	for(i=2;i<m;i++)
	{
		if(A[i] == 0)
		{
			A[i] = 1;
		//	printf("%d ",i);
			B[n++] = i;
			if(n == 3000)
				break;
			k=i;
			for(j=i+1;j<m;j++)
			{
				if(A[j] == 0)
				{
					k--;
					if(k == 0)
					{
						A[j] = 1;
						k = i;
					}
				}
			}
		}
	}
	scanf("%d",&n);
	while(n != 0)
	{
		printf("%d\n",B[n-1]);
		scanf("%d",&n);
	}
//	printf("n = %d\n",n);
	return 0;
}
