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
	long long int A[25][25],B[50];
	for(u=0;u<test;u++)
	{
	//	memset(A,0,sizeof(A));
	//	memset(B,0,sizeof(B));
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
		//	if(B[i+1] == 1)
		//		A[i][1] = A[i-1][1];
		//	else
		//		A[i][1] = i;
			A[0][i] = 0;
		}
		A[1][1] = 1;
		for(i=0;i<=n+1;i++)
		{
			for(j=0;j<=n+1;j++)
				cout << A[i][j] << " ";
			cout << "\n";
		}
		for(i=1;i<25;i++)
		{
			for(j=1;j<=i;j++)
			{
				if(i == 1 && j == 1)
					continue;
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
		cout << "\n";
		for(i=0;i<=n+1;i++)
		{
			for(j=0;j<=n+1;j++)
				cout << A[i][j] << " ";
			cout << "\n";
		}
		cout << A[n][n] << endl;
		cout << A[n+1][n+1] << endl;
	}
}

