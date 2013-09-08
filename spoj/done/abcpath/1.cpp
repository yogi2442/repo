#include <cstdio>

int C[60][60] = {{0}};
char A[60][60];
int r,c;

int func(int,int,int);

int main()
{
	int i,j,k,l,m,n,B[3600][2],ans,max,u;
	char ch;

	scanf("%d%d",&r,&c);
	u = 1;
	while( r != 0 && c != 0)
	{
		scanf("%c",&ch);
	
		for(i=0;i<=r;i++)
			for(j=0;j<=c;j++)
				C[i][j]= 0;

	//	printf("r = %d c = %d\n",r,c);
		k=0;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				scanf("%c",&A[i][j]);
				if(A[i][j] == 'A')
				{
					B[k][0] = i;
					B[k][1] = j;
					k++;
				}
			}
			scanf("%c",&ch);
		}
	/*	printf("number of A's = %d\n",k);

		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				printf("%c",A[i][j]);
			}
			printf("\n");
		}*/
		max = 0;
		for(i=0;i<k;i++)
		{
	//		printf("%d %d\n",B[i][0],B[i][1]);
			ans = func(B[i][0],B[i][1],'A');
			if(ans > max)
				max = ans;
		}
		printf("Case %d: %d\n",u,max);
		u++;
		scanf("%d%d",&r,&c);
	}
	return 0;


}

int func(int i,int j,int num)
{
	int k,l,ans,max=A[i][j]-'A'+1;
	C[i][j] = 1;
	for(k=-1;k<2;k++)
	{
		for(l=-1;l<2;l++)
		{
			if(i+k >=0 && i+k < r && j+l >= 0 && j+l < c)
			{
				if(C[i+k][j+l] == 0 && A[i+k][j+l] == num+1)
				{
					C[i+k][j+l] = 1;
					ans = func(i+k,j+l,num+1);
				//	C[i+k][j+l] = 0;
					if(ans > max)
						max = ans;
				}
			}
		}
	}
//	C[i][j] = 0;
	return max;
}
