#include <cstdio>
#include <cstdlib>

int main()
{
	int i,j,k,l,B[200002]={0},*A,C[200002];
	int n,m,sum,max,p,q;
	scanf("%d",&n);
	A = (int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	int max1=0;
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&p,&q);
		p--;
		q--;
		k=0;
		sum = A[p];
		max = sum;
		B[A[p]+100000] = 1;
		C[k++] = A[p];
		for(j=p+1;j<=q;j++)
		{
			if(sum < 0)
			{
				while(k>0)
				{
					B[C[--k]+100000] = 0;
				}
				sum = A[j];
				B[A[j]+100000] = 1;
				C[k++] = A[j];
			}
			else
			{
				if(B[A[j] + 100000] == 0)
				{
					sum += A[j];
					C[k++] = A[j];
					B[A[j]+100000] = 1;
				//	printf("A[j] = %d ans sum = %d and C[k-1] = %d\n",A[j],sum,C[k-1]);
				}
			}

			if(max <= sum)
				max = sum;
		}

		while(k>0)
			B[C[--k]+100000] = 0;
		printf("%d\n",(max > 0) ? max : max1);
	}
	return 0;


}
