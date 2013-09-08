#include <cstdio>
#include <cstdlib>

int main()
{
	int *A,i,j,k,l,m,n,u,t,prev,max = 63000000,a1,a2,a3,yogi,a,b;
	A = (int*)malloc(sizeof(int)*max);

	A[0] = 0;
	A[1] = 1;

	for(i=2;i<max;i++)
	{
		A[i] = (A[i-1] + A[i-2])%1000000007;
	}


	scanf("%d",&t);

	for(u=0;u<t;u++)
	{
		scanf("%d%d",&n,&m);
		if(n < max - 2 && m < max - 2)
		{
			a = A[n+1];
			b = A[m+2];

			printf("%d\n",(b-a)%1000000007);
		}

		else if(n < max - 2 && m > max - 2)
		{
			a = A[n+1];
			
			a1 = A[max-2];
			a2 = A[max-1];
			i = max;
			while(i <= m+2)
			{
				a3 = (a2 + a1)%1000000007;
				
				a1 = a2;
				a2 = a3;
				i++;
			}
			printf("%d\n",(a3-a)%1000000007);
		}
		else if(n > max - 2 && m > max - 2)
		{
			a1 = A[max-2];
			a2 = A[max-1];
			i = max;
			while(i <= m+2)
			{
				a3 = (a2 + a1)%1000000007;
			
				if(i == n+1)
					yogi = a3;
				a1 = a2;
				a2 = a3;
				i++;
			}
			printf("a3 = %d yogi = %d\n",a3,yogi);
			printf("%d\n",(a3-yogi)%1000000007);
		}
	}
	return 0;
}
