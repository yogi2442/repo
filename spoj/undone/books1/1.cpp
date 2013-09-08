#include <cstdio>
#include <cstdlib>
#include <iostream>

int main()
{
	int test,u,i,j,k,l,m,n,*A,*B,low,high,mid,flag,max;
	long long *C,sum,sum1;
	float yogi;
	scanf("%d",&test);
	for(u=0;u<test;u++)
	{
		sum=0;
		scanf("%d%d",&n,&k);
		A = (int*)malloc(sizeof(int)*n);
		C = (long long*)malloc(sizeof(long long)*n);
		B = (int*)malloc(sizeof(int)*n);

		max=-1;
		for(i=0;i<n;i++)
		{
			scanf("%d",&A[i]);
			max = (max < A[i]) ? A[i] : max;
			sum = sum + A[i];
			B[i]=0;
			C[i] = sum;
		}
		if(n == k)
		{
			for(i=0;i<n;i++)
			{
				if(i<n-1)
					printf("%d / ",A[i]);
				else
					printf("%d\n",A[i]);
			}
		}
		else if(k == 1)
		{
			for(i=0;i<n;i++)
			{
				if(i == n-1)
					printf("%d\n",A[i]);
				else
					printf("%d ",A[i]);
			}
		}
		else
		{
			low = sum/k;
			low = (low < max) ? max : low;
			high = sum;
			l = k;
			while(low < high)
			{
				k = l;
				mid = (low+high)/2;
			//	printf("low = %d   high = %d and mid  = %d\n",low,high,mid);
				flag = 1;
				sum1=0;
				for(i=n-1;i>=0;i--)
				{
					sum1 += A[i];
					if(sum1 > mid)
					{
						i++;
						k--;
						sum1=0;
					}
					if(k <= 0)
						flag=0;
				}
			//	printf("k = %d\n",k);
				if(flag == 1)
					high = mid;
				else
					low = mid + 1;
			}
		//	printf("low = %d   high = %d and mid  = %d\n",low,high,mid);

			k=l;
			sum1=0;
			for(i=n-1;i>=0;i--)
			{
				sum1 += A[i];
				if(sum1 > high)
				{
					i++;
					B[i]=1;
					k--;
					sum1=0;
					if(i == k)
						break;
				}
				else if(sum1 == high)
				{
					k--;
					B[i]=1;
					sum1=0;
					if(i == k)
						break;
				}

			//	printf("i = %d  k = %d\n",i,k);
			}
			for(j=i;i>0;i--)
				B[i]=1;

			for(i=0;i<n;i++)
			{
				if(B[i] == 1)
					printf("/ ");
				if(i == n-1)
					printf("%d\n",A[i]);
				else
					printf("%d ",A[i]);
			}

		}
		free(A);
		free(B);
		free(C);
	}
	return 0;
}
