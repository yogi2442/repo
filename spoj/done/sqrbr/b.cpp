#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
	int i,j,k,l,test,u;
	cin >> test;
	int n;
	int A[25][25],B[50];
	for(u=0;u<test;u++)
	{
		cin >> n >> k;
		for(i=0;i<50;i++)
			B[i] = 0;
		for(i=0;i<k;i++)
		{
			cin >> j;
			B[j] = 1;
		}
		for(i=0;i<25;i++)
			for(j=0;j<25;j++)
				A[i][j] = 0;
		for(i=0;i<25;i++)
		{
			A[i][0] = 0;
			A[i][1] = i;
			A[0][i] = 0;
		}
		for(i=2;i<25;i++)
		{
			for(j=2;j<=i;j++)
			{
				if(B[i+j] == 1)
				{
					A[i][j] = A[i-1][j];
				}
				else
				{
					A[i][j] = A[i-1][j] + A[i][j-1];
				}
			}
		}
		cout << A[n][n] << endl;
	}
}

