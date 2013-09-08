#include <cstdio>
#include <iostream>

int main()
{
	char A[2013][2013];
	int i,j,k,l;
	int n,m,count;
	char ch;
	scanf("%c",&ch);
	while(ch != 'Q')
	{
		for(i=0;i<2013;i++)
			for(j=0;j<2013;j++)
				A[i][j] = '0';
		count=0;
		i = 1002;
		j = 1002;
		A[i][j] = '1';
		while(ch != 'Q')
		{
		//	printf("%c",ch);
			if(ch == 'U')
			{
				j++;
				if(A[i][j] == '1')
					count++;
				else
					A[i][j] = '1';
			}
			else if(ch == 'D')
			{
				j--;
				if(A[i][j] == '1')
					count++;
				else
					A[i][j] = '1';
			}
			else if(ch == 'L')
			{
				i--;
				if(A[i][j] == '1')
					count++;
				else
					A[i][j] = '1';
			}
			else if(ch == 'R')
			{
				i++;
				if(A[i][j] == '1')
					count++;
				else
					A[i][j] = '1';
			}
			scanf("%c",&ch);
		}
		printf("%d\n",count);
		scanf("%c",&ch);
		scanf("%c",&ch);
	//	printf("\n");
	}
	return 0;
}
