#include <cstdio>

int main()
{
	int t,u,i,j,k,l,m,n;
	scanf("%d",&t);
	for(u=0;u<t;u++)
	{
		scanf("%d",&n);
		if(n == 1)
			printf("poor conductor\n");
		else
		{
			printf("%d ",(n+3)/5);
			m = n%10;
			if(m == 1 || m == 2)
				printf("W L\n");
			if(m == 3 || m == 0)
				printf("A L\n");
			if(m == 4 || m == 9)
				printf("A R\n");
			if(m == 5 || m == 8)
				printf("M R\n");
			if(m == 6 || m == 7)
				printf("W R\n");
		}

		
	}
}
