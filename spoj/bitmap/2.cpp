#include <cstdio>
#include <cstdlib>
#include <cmath>

int main()
{
	int i,j,m,n,A[200][200],dist,x,y1,y2;
	int t,u,r,c,k,flag;
	char ch;
	scanf("%d",&t);
	for(u=0;u<t;u++)
	{
		scanf("%d%d",&r,&c);
		scanf("%c",&ch);

		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				scanf("%c",&ch);
				A[i][j] = ch - '0';
			}
			scanf("%c",&ch);
		}
		
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				flag=0;
				for(dist=0;;dist++)
				{
					for(k=-1*dist;k<=dist;k++)
					{
						x = i + k;
						y1 = j+(dist-abs(k));
						y2 = j-(dist-abs(k));

						if(x >= 0 && x < r)
						{
							if(y1 >=0 && y1 < c)
							{
								if(A[x][y1] == 1)
								{
									flag = 1;
									break;
								}
							}
							if(y2 >= 0 && y2 < c)
							{
								if(A[x][y2] == 1)
								{
									flag=1;
									break;
								}
							}
						}
					}
					if(flag==1)
					{
						if(j == c-1)
							printf("%d\n",dist);
						else
							printf("%d ",dist);
						break;
					}
				}
			}
		}
	}
	return 0;
}
