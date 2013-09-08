#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int *A,*B;
	A = (int*)malloc(sizeof(int)*500001);
	B = (int*)malloc(sizeof(int)*10000001);
//	printf("yogi\n");
	int i,j,k,l,m,n;
	A[0] = 0;
	B[0] = 1;
	for(i=1;i<=500000;i++)
	{
		n = A[i-1] - i;
		if(n > 0)
		{
			if(B[n] == 0)
			{
				A[i] = n;
				B[n] = 1;
			}
			else
			{
				n = A[i-1] + i;
				B[n] = 1;
				A[i] = n;
			}
		}
		else
		{
			n = A[i-1] + i;
			B[n] = 1;
			A[i] = n;
		}
	//	printf("%d ",v[i]);
	}
//	printf("yogi\n");
	scanf("%d",&n);
	while(n != -1)
	{
		printf("%d\n",A[n]);
		scanf("%d",&n);
	}
	return 0;
}
