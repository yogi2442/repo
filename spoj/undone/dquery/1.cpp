#include <cstdio>
#include <cstdlib>

int main()
{
	int i,j,k,l,A[1000001],m,n;
	bool B[1000001] = {false};

	scanf("%d%d",&n,&m);
	B[m] = true;
	A[1] = 1;
	for(i=2;i<=n;i++)
	{
		scanf("%d",&m);
		if(B[m] == false)
		{
			A[i] = A[i-1] + 1;
			B[m] = true;
		}
		else
			A[i] = A[i-1];
	}
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&k,&l);
		printf("%d\n",A[l]-A[k]);
	}
	return 0;
}
