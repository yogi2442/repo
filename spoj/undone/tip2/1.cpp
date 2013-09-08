#include <cstdio>
#include <iostream>
#include <cstdlib>

#define y 1000000000001


int main()
{

	long long *A,nu=100000000;
//	long long A[y];
	A = (long long*)malloc(sizeof(long long)*(nu+1));
	long long i,j,k,l,m,n,min,p,q,r,C[10];
	for(i=1;i<=nu;i++)
	{
		A[i] = i;
	}
	long double a,b;
	min = 21;
	printf("%lld\n",min);
	for(i=2;i<=nu;i++)
	{
		if(A[i] == i)
		{
			for(j=2*i;j<=nu;j=j+i)
			{
				A[j] = A[j] - A[j]/i;
			}
		}
		if(A[i-1] == i-1)
			A[i-1] = i - 2;
		if(i>23)
		{
			for(k=0;k<10;k++)
				C[k]=0;
			r = i-1;
			p = i-1;
			q = A[i-1];
			while(p > 0)
			{
				C[p%10]++;
				p = p/10;
			}
			while(q > 0)
			{
				C[q%10]--;
				q = q/10;
			}
			for(k=0;k<10;k++)
				if(C[k] != 0)
					break;
			if(k == 10)
			{
				//	printf("%d = %d\n",r,A[r]);
				a = (r*1.0)/A[r];
				b = (min*1.0)/A[min];
				if(a <= b)
				{
					min = r;
					//	printf("%d = %d   %lf\n",min,A[min],a);
					printf("%lld\n",min);
				}	
			}
		}
	}
	exit(0);
/*	A[1] = 1;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		if(m > 21)
	//		printf("%d\n",B[m]);
		else
			printf("No solution.\n");
	}*/
	return 0;

}
