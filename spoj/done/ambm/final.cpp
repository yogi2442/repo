#include <cstdio>
#include <cstdlib>
#include <algorithm>
//#include <sort>

using namespace std;

int func(long long*,int,long long);
long long *B;
int index;
int main()
{
	int i,j,k,l;
	long long n,m,*A;
	A = (long long*)malloc(sizeof(long long)*60);
	B = (long long*)malloc(sizeof(long long)*60);
	int test,u;
	scanf("%d",&test);
	for(u=0;u<test;u++)
	{
		index = 0;
		scanf("%lld%d",&n,&k);
		A[0] = 0;
		for(i=1;i<=k;i++)
		{
			scanf("%d",&l);
			A[i] = (2*A[i-1]) + l;
		//	printf("%lld ",A[i]);
		}
	//	printf("\n");
		sort(A+1,A+1+k);
		m=0;
		for(i=k;i>0;i--)
		{
			m = m + A[i];
		}
		if(m < n)
		{
			printf("-1\n");
			continue;
		}
		else
		{
			l = func(A,k,n);
			if(l == 0)
				printf("-1\n");
			else if(l == 1)
			{
			//	printf("found\n");
				sort(B,B+index);

				i=1;j=0;
				while(i<k+1 && j<index)
				{
					if(A[i] == B[j])
					{
						if(j == index - 1)
							printf("%d\n",i);
						else
							printf("%d ",i);
						j++;
					}
					i++;
				}

			/*	for(i=0;i<index;i++)
				{
					if(index -1 == i)
						printf("%lld\n",B[i]);
					else
						printf("%lld ",B[i]);
				}
				*/
			}
		}
	}
	return 0;
}

int func(long long *A,int k, long long n)
{

	if(n < 0)
		return 0;
	else if(n == 0)
		return 1;
	else if(k == 0)
		return 0;
	
	int i,j;
	
	i = func(A,k-1,n-A[k]);
	if(i == 1)
	{
		B[index++] = A[k];
		return 1;
	}
	
	j = func(A,k-1,n);
	if(j == 1)
		return 1;
	
	return 0;
}

