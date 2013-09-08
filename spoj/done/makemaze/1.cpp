#include <cstdio>
#include <cstdlib>

char A[22][22];
int B[400][2],C[22][22];
int r,c;

int func(int,int,int,int);

int main()
{
	int i,j,k,l,m,n,t,u,count,ans;
	char ch;
	scanf("%d",&t);
	for(u=0;u<t;u++)
	{
		scanf("%d%d",&r,&c);
		scanf("%c",&ch);
		count=0;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				C[i][j] = 0;
				scanf("%c",&A[i][j]);
				if(i == 0 || i == r-1)
				{
					if(A[i][j] == '.')
					{
						B[count][0] = i;
						B[count][1] = j;
						count++;
					}
				}
				if((j == 0 || j == c-1) && (i > 0 && i < r-1))
				{
					if(A[i][j] == '.')
					{
						B[count][0] = i;
						B[count][1] = j;
						count++;
					}
				}
			}
			scanf("%c",&ch);
		}
	//	printf("%d\n",count);
		if(count != 2)
		{
			printf("invalid\n");
			continue;
		}

	//	printf("start %d %d  end %d %d\n",B[0][0],B[0][1],B[1][0],B[1][1]);
		else
		{
			ans = func(B[0][0],B[0][1],B[1][0],B[1][1]);
			if(ans == 1)
				printf("valid\n");
			else
				printf("invalid\n");
		}
	/*	for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				printf("%c",A[i][j]);
			}
			printf("\n");
		}*/
	}
	return 0;
}

int func(int s1,int s2,int e1,int e2)
{
//	printf("%d %d\n",s1,s2);
	int ans=0;
	if(s1-1 >= 0)
	{
		if(A[s1-1][s2] == '.' && s1-1 == e1 && s2 == e2)
			return 1;
		else if(A[s1-1][s2] == '.' && C[s1-1][s2] == 0)
		{
			C[s1-1][s2] = 1;
			ans = func(s1-1,s2,e1,e2);
			C[s1-1][s2] = 0;
			if(ans == 1)
				return 1;
		}
	}
	if(s1+1 < r)
	{
		if(A[s1+1][s2] == '.' && s1+1 == e1 && s2 == e2)
			return 1;
		else if(A[s1+1][s2] == '.' && C[s1+1][s2] == 0)
		{
			C[s1+1][s2] = 1;
			ans = func(s1+1,s2,e1,e2);
			C[s1+1][s2] = 0;
			if(ans == 1)
				return 1;
		}
	}
	if(s2-1 >= 0)
	{
		if(A[s1][s2-1] == '.' && s1 == e1 && s2-1 == e2)
			return 1;
		else if(A[s1][s2-1] == '.' && C[s1][s2-1] == 0)
		{
			C[s1][s2-1] = 1;
			ans = func(s1,s2-1,e1,e2);
			C[s1][s2-1] = 0;
			if(ans == 1)
				return 1;
		}
	}
	if(s2+1 < c)
	{
		if(A[s1][s2+1] == '.' && s1 == e1 && s2+1 == e2)
			return 1;
		else if(A[s1][s2+1] == '.' && C[s1][s2+1] == 0)
		{
			C[s1][s2+1] = 1;
			ans = func(s1,s2+1,e1,e2);
			C[s1][s2+1] = 0;
			if(ans == 1)
				return 1;
		}
	}
	return 0;
}
