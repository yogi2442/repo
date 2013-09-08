#include <cstdio>
#include <cstdlib>

int main()
{
	char A[300][300],ch;
	int i,j,k,l,m,n,games,t,u,cross,circle,xcount,ocount,row,col,win,r,c;

	cross = 0;
	circle = 0;
	scanf("%d",&t);
	for(u=0;u<t;u++)
	{
		win = 0;
		scanf("%d%d%d",&col,&row,&k);
		scanf("%c",&ch);
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
				scanf("%c",&A[i][j]);
			scanf("%c",&ch);
		}
	/*	for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
				printf("%c",A[i][j]);
			printf("\n");
		}
*/
		for(i=0;i<row;i++)
		{
			xcount = 0;
			ocount = 0;
			for(j=0;j<col;j++)
			{
				if(A[i][j] == 'x')
				{
					xcount++;
					ocount = 0;
				}
				else if(A[i][j] == 'o')
				{
					ocount++;
					xcount = 0;
				}
				else
				{
					xcount = 0;
					ocount = 0;
				}
				if(xcount ==  k)
				{
				//	printf("cross wins i = %d and j = %d\n",i,j);
					cross++;
					win = 1;
					break;
				}
				else if(ocount == k)
				{
				//	printf("circle wins i = %d and j = %d\n",i,j);
					circle++;
					win = 1;
					break;
				}
			}
			if(win == 1)
			{
				break;
			}
		}

		if(win == 0)
		{
			for(j=0;j<col;j++)
			{
				xcount = 0;
				ocount = 0;
				for(i=0;i<row;i++)
				{
					if(A[i][j] == 'x')
					{
						xcount++;
						ocount = 0;
					}
					else if(A[i][j] == 'o')
					{
						ocount++;
						xcount=0;
					}
					else
					{
						xcount = 0;
						ocount = 0;
					}
					if(xcount ==  k)
					{
					//	printf("cross wins i = %d and j = %d\n",i,j);
						cross++;
						win = 1;
						break;
					}
					else if(ocount == k)
					{
					//	printf("circle wins i = %d and j = %d\n",i,j);
						circle++;
						win = 1;
						break;
					}
				}
				if(win == 1)
					break;
			}
		}
		
		if(win == 0)
		{
			for(i=0;i<col;i++)
			{
				r = 0;
				c = i;
				
				xcount = 0;
				ocount = 0;
				while(r < row && c < col)
				{
					if(A[r][c] == 'x')
					{
						xcount++;
						ocount = 0;
					}
					else if(A[r][c] == 'o')
					{
						ocount++;
						xcount = 0;
					}
					else
					{
						xcount = 0;
						ocount = 0;
					}
					if(xcount ==  k)
					{
					//	printf("cross wins i = %d and j = %d\n",r,c);
						cross++;
						win = 1;
						break;
					}
					else if(ocount == k)
					{
					//	printf("circle wins i = %d and j = %d\n",r,c);
						circle++;
						win = 1;
						break;
					}
					r++;c++;
				}
				if(win == 1)
					break;

				xcount = 0;
				ocount = 0;

				r = row - 1;
				c = i;

				while(r >= 0 && c < col)
				{
					if(A[r][c] == 'x')
					{
						xcount++;
						ocount = 0;
					}
					else if(A[r][c] == 'o')
					{
						ocount++;
						xcount = 0;
					}
					else
					{
						xcount = 0;
						ocount = 0;
					}
					if(xcount ==  k)
					{
						cross++;
						win = 1;
						break;
					}
					else if(ocount == k)
					{
						circle++;
						win = 1;
						break;
					}
					r--;c++;
				}
				if(win == 1)
					break;
			}

			if(win == 0)
			{
				for(i=0;i<row;i++)
				{
					xcount = 0;
					ocount = 0;

					r = i;
					c = 0;

					while(r < row && c < col)
					{
						if(A[r][c] == 'x')
						{
							xcount++;
							ocount = 0;
						}
						else if(A[r][c] == 'o')
						{
							ocount++;
							xcount = 0;
						}
						else
						{
							xcount = 0;
							ocount = 0;
						}
						if(xcount ==  k)
						{
							cross++;
							win = 1;
							break;
						}
						else if(ocount == k)
						{
							circle++;
							win = 1;
							break;
						}
						r++;c++;
					}
					if(win == 1)
						break;

					xcount = 0;
					ocount = 0;

					r = i;
					c = 0;

					while(r >= 0 && c < col)
					{
						if(A[r][c] == 'x')
						{
							xcount++;
							ocount = 0;
						}
						else if(A[r][c] == 'o')
						{
							ocount++;
							xcount = 0;
						}
						else
						{
							xcount = 0;
							ocount = 0;
						}
						if(xcount ==  k)
						{
							cross++;
							win = 1;
							break;
						}
						else if(ocount == k)
						{
							circle++;
							win = 1;
							break;
						}
						r--;c++;
					}
					if(win == 1)
						break;
				}
			}
		}

//	printf("%d:%d\n",cross,circle);
	}
	printf("%d:%d\n",cross,circle);
	return 0;

}
