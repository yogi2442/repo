#include <cstdio>
#include <cstdlib>

int main()
{
	int i,j,k,l,m,n,num,*A;
	A = (int*)malloc(sizeof(int)*10000001);
//	int A[10000001];
	int t,u,head,tail,count;
	A[1]=1;
	A[2]=2;
	A[3]=3;
	A[4]=3;
	A[5]=4;
	A[6]=4;
	A[7]=4;
	A[8]=5;
	A[9]=5;
	A[10]=5;
	
	head = 5;
	tail = 11;
	count=0;
	num=6;
	
	while(tail <= 1000000)
	{
		if(A[head] == A[head+1])
		{
			head++;
			count++;
		}
		else
		{
			count++;
			for(i=0;i<count;i++)
			{
				for(j=0;j<A[head];j++)
				{
					A[tail] = num;
					tail++;
				}
				num++;
			}
			head++;
			count=0;
		}
	}
	
	


	scanf("%d",&t);
	for(u=0;u<t;u++)
	{
		scanf("%d",&n);
		printf("Case #%d: %d\n",u+1,A[n]);
	}
	return 0;
}
