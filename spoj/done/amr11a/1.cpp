#include <cstdio>
#include <cstdlib>

int main()
{
	int i,j,t,u,row,col,A[600][600],B[600][600],health;
	scanf("%d",&t);
	for(u=0;u<t;u++)
	{
		scanf("%d%d",&row,&col);
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				scanf("%d",&A[i][j]);
			}
		}
		B[0][0] = 1;
		for(i=1;i<col;i++)
		{
			B[0][i] = B[0][i-1] + A[0][i];
		}
		for(i=1;i<row;i++)
		{
			B[i][0] = B[i-1][0] + A[i][0];
		}

		health = 1;
		for(i=1;i<row;i++)
		{
			for(j=1;j<col;j++)
			{
				if(B[i][j-1] < B[i-1][j])
				{
					if(B[i-1][j] <= 0)
					{
						health = health + 1 - B[i-1][j];
						B[i-1][j] = 1;
					}
					B[i][j] = B[i-1][j] + A[i][j];
				}
				else
				{
					if(B[i][j-1] <= 0)
					{
						health = health + 1 - B[i][j-1];
						B[i][j-1] = 1;
					}
					B[i][j] = B[i][j-1] + A[i][j];
				}
			}
		}
		if(B[row-1][col-1] <= 0)
		{
			health = health + 1 - B[row-1][col-1];
		}
	//	printf("%d\n",B[row-1][col-1]);
		printf("%d\n",health);
	}
	return 0;
}
