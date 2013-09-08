#include <cstdio>
#include <cstdlib>

int main()
{
	int i,j,k,l,time[60][60],toll[60][60],n,m;
	scanf("%d%d",&n,&m);
	while(n != 0 && m != 0)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&time[i][j]);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&toll[i][j]);
		

		scanf("%d%d",&n,&m);
	}
}
