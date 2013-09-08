#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>

int func(char**,int,int,int**,int,int,char*,int);

int main()
{
	
	char **C,*str,ch;
	C = (char**)malloc(sizeof(char*)*100);
	str = (char*)malloc(sizeof(char)*20);
	strcpy(str,"ALLIZZWELL");
	int i,j,k,l,m,n,test,u,row,col,ans,flag,**A,**B;
	B = (int**)malloc(sizeof(int*)*100);
	for(i=0;i<100;i++)
	{
		C[i] = (char*)malloc(sizeof(char)*100);
		B[i] = (int*)malloc(sizeof(int)*100);
	}
	A = (int**)malloc(sizeof(int*)*10000);
	for(i=0;i<10000;i++)
		A[i] = (int*)malloc(sizeof(int)*2);
	scanf("%d",&test);
	for(u=0;u<test;u++)
	{
		scanf("%d%d",&row,&col);
		scanf("%c",&ch);
		k=0;
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				scanf("%c",&C[i][j]);
				if(C[i][j] == 'A')
				{
					A[k][0] = i;
					A[k++][1] = j;
				}
				B[i][j] = 0;
			}
			scanf("%c",&ch);
		}
		scanf("%c",&ch);
	/*	for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				printf("%c",C[i][j]);
			}
			printf("\n");
		}*/
	//	printf("k = %d\n",k);
		flag=0;
		for(i=0;i<k;i++)
		{
			B[A[i][0]][A[i][1]] = 1;
			ans = func(C,row,col,B,A[i][0],A[i][1],str,1);
			if(ans == 1)
			{
				flag=1;
				break;
			}
			B[A[i][0]][A[i][1]] = 0;
		}
		if(flag==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}


int func(char **C,int row,int col,int **B,int i,int j,char *str,int index)
{

	if(index == 10)
		return 1;
	int ans;
	if(i-1 >= 0 && i-1 < row)
	{
		if(j-1 >= 0 && j-1 < col)
		{
			if(C[i-1][j-1] == str[index] && B[i-1][j-1] == 0)
			{
				B[i-1][j-1] = 1;
				ans = func(C,row,col,B,i-1,j-1,str,index+1);
				if(ans == 1)
					return 1;
				B[i-1][j-1] = 0;
			}
		}
		if(j >= 0 && j < col)
		{
			if(C[i-1][j] == str[index] && B[i-1][j] == 0)
			{
				B[i-1][j] = 1;
				ans = func(C,row,col,B,i-1,j,str,index+1);
				if(ans == 1)
					return 1;
				B[i-1][j] = 0;
			}
		}
		if(j+1 >= 0 && j+1 < col)
		{
			if(C[i-1][j+1] == str[index] && B[i-1][j+1] == 0)
			{
				B[i-1][j+1] = 1;
				ans = func(C,row,col,B,i-1,j+1,str,index+1);
				if(ans == 1)
					return 1;
				B[i-1][j+1] = 0;
			}
		}
	}
	if(i >= 0 && i < row)
	{
		if(j-1 >= 0 && j-1 < col)
		{
			if(C[i][j-1] == str[index] && B[i][j-1] == 0)
			{
				B[i][j-1] = 1;
				ans = func(C,row,col,B,i,j-1,str,index+1);
				if(ans == 1)
					return 1;
				B[i][j-1] = 0;
			}
		}
		if(j+1 >= 0 && j+1 < col)
		{
			if(C[i][j+1] == str[index] && B[i][j+1] == 0)
			{
				B[i][j+1] = 1;
				ans = func(C,row,col,B,i,j+1,str,index+1);
				if(ans == 1)
					return 1;
				B[i][j+1] = 0;
			}
		}
	}
	if(i+1 >= 0 && i+1 < row)
	{
		if(j-1 >= 0 && j-1 < col)
		{
			if(C[i+1][j-1] == str[index] && B[i+1][j-1] == 0)
			{
				B[i+1][j-1] = 1;
				ans = func(C,row,col,B,i+1,j-1,str,index+1);
				if(ans == 1)
					return 1;
				B[i+1][j-1] = 0;
			}
		}
		if(j >= 0 && j < col)
		{
			if(C[i+1][j] == str[index] && B[i+1][j] == 0)
			{
				B[i+1][j] = 1;
				ans = func(C,row,col,B,i+1,j,str,index+1);
				if(ans == 1)
					return 1;
				B[i+1][j] = 0;
			}
		}
		if(j+1 >= 0 && j+1 < col)
		{
			if(C[i+1][j+1] == str[index] && B[i+1][j+1] == 0)
			{
				B[i+1][j+1] = 1;
				ans = func(C,row,col,B,i+1,j+1,str,index+1);
				if(ans == 1)
					return 1;
				B[i+1][j+1] = 0;
			}
		}
	}
	return 0;
}
