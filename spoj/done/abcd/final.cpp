#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int n,i,j,k,l,m;
	char **A,ch;
	scanf("%d",&n);
	A = (char**)malloc(sizeof(char*)*2);
	
	m = 2*n;
	A[0] = (char*)malloc(sizeof(char)*m);
	A[1] = (char*)malloc(sizeof(char)*m);
	
	scanf("%s",A[0]);
	
	for(i=0;i<m;i=i+2)
	{
		if(A[0][i] == 'A')
		{
			if(A[0][i+1] == 'B')
			{
				A[1][i] = 'C';
				A[1][i+1] = 'D';
			}
			if(A[0][i+1] == 'C')
			{
				A[1][i] = 'B';
				A[1][i+1] = 'D';
			}
			if(A[0][i+1] == 'D')
			{
				A[1][i] = 'B';
				A[1][i+1] = 'C';
			}
		}
		else if(A[0][i] == 'B')
		{
			if(A[0][i+1] == 'A')
			{
				A[1][i] = 'C';
				A[1][i+1] = 'D';
			}
			if(A[0][i+1] == 'C')
			{
				A[1][i] = 'A';
				A[1][i+1] = 'D';
			}
			if(A[0][i+1] == 'D')
			{
				A[1][i] = 'A';
				A[1][i+1] = 'C';
			}
		}
		else if(A[0][i] == 'C')
		{
			if(A[0][i+1] == 'A')
			{
				A[1][i] = 'B';
				A[1][i+1] = 'D';
			}
			if(A[0][i+1] == 'B')
			{
				A[1][i] = 'A';
				A[1][i+1] = 'D';
			}
			if(A[0][i+1] == 'D')
			{
				A[1][i] = 'A';
				A[1][i+1] = 'B';
			}
		}
		else if(A[0][i] == 'D')
		{
			if(A[0][i+1] == 'A')
			{
				A[1][i] = 'B';
				A[1][i+1] = 'C';
			}
			if(A[0][i+1] == 'B')
			{
				A[1][i] = 'A';
				A[1][i+1] = 'C';
			}
			if(A[0][i+1] == 'C')
			{
				A[1][i] = 'A';
				A[1][i+1] = 'B';
			}
		}
		if(i > 0)
		{
			if(A[1][i-1] == A[1][i])
			{
				ch = A[1][i];
				A[1][i] = A[1][i+1];
				A[1][i+1] = ch;
			}
		}
		if(i == m-2)
			printf("%c%c\n",A[1][i],A[1][i+1]);
		else
			printf("%c%c",A[1][i],A[1][i+1]);
	}

	return 0;
}
