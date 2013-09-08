#include <cstdio>
#include <iostream>
#include <cstdlib>

int main()
{
	int j,k,l,m,n,d;
	int i;
	scanf("%d%d",&n,&d);
	int *A;
	while(n != 0 && d != 0)
	{
		
		m = 0;
		for(i=2;i<=n;i++)
			m = (m+d)%i;
		printf("%d %d %d\n",n,d,m+1);



	/*	A = (int*)malloc(sizeof(int)*n);
		for(i=0;i<n;i++)
		{
			A[i]=1;
		}
		m = n;
		i=0;
		while(n > 1)
		{
			l = d%n+1;
			while(1)
			{
				if(A[i % m] == 1)
					l--;
				if(l == 0)
					break;
				else if(l == 1)
					A[i%m]=0;
				i++;
			}
		//	A[(i-1)%m]=0;
			n--;
		}
	//	for(i=0;i<m;i++)
	//		if(A[i] == 1)
	//			break;
		printf("%d %d %d\n",m,d,(i+1)%m);
		free(A);*/
		scanf("%d%d",&n,&d);
	}
	return 0;
}

