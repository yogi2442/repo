#include <cstdio>
#include <cstdlib>

int main()
{
	int i,j,k,l,*A,*B,*C,*D;
	int n,m,sum,max,p,q;
	scanf("%d",&n);
	A = (int*)malloc(sizeof(int)*n);
	B = (int*)malloc(sizeof(int)*n);
	C = (int*)malloc(sizeof(int)*n);
	D = (int*)malloc(sizeof(int)*n);
	scanf("%d",&A[0]);
	j=0;
	sum = A[0];
	B[0] = 1;
	C[0] = j;
	D[0] = sum;
	for(i=1;i<n;i++)
	{
		scanf("%d",&A[i]);
		if(A[i] > A[i] + sum)
		{
			sum = A[i];
			B[i] = 1;
			j++;
			C[i] = j;
		}
		else
		{
			sum += A[i];
			C[i] = j;
			B[i]=0;
		}
		if(sum > D[i-1])
		{
			D[i] = sum;
		}
		else
			D[i] = D[i-1];
		
	}
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&p,&q);
		p--;
		q--;
		if(C[q] == C[p])
		{
			max = D[q] - D[p];
			if(B[i] == 1)
				max = max + A[p];
		}
		else
			max = D[q];
		printf("%d\n",max);
		
/*		k=0;
		sum = A[p];
		max = sum;
		for(j=p+1;j<=q;j++)
		{
			if(sum < 0)
				sum = A[j];
			else
					sum += A[j];
			if(max <= sum)
				max = sum;
		}
		printf("%d\n",max);*/
	}
	return 0;


}
