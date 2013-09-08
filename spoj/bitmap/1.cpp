#include <cstdio>
#include <cstdlib>
#include <cmath>

int main()
{
	int i,j,m,n,A[200][200],x[40000][2],dist;
	int t,u,r,c,k,min,value,l,flag;
	char ch;
	scanf("%d",&t);
	for(u=0;u<t;u++)
	{
		scanf("%d%d",&r,&c);
		scanf("%c",&ch);

		k = 0;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				scanf("%c",&ch);
				A[i][j] = ch - '0';
			/*	if(A[i][j] == 1)
				{
					x[k][0] = i;
					x[k++][1] = j;
				}*/
			}
			scanf("%c",&ch);
		}
		
	/*	for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				min = abs(x[0][0] - i) + abs(x[0][1] - j);
				for(l=1;l<k;l++)
				{
					value = abs(x[l][0] - i) + abs(x[l][1] - j);
					if(min > value)
						min = value;
					if(min == 0)
						break;
				}
				if(j == c-1)
					printf("%d\n",min);
				else
					printf("%d ",min);

			}
		}
*/
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				flag=0;
				for(dist=0;;dist++)
				{
					for(k=-1*dist;k<=dist;k++)
					{
						if(A[i+k][j+(dist-abs(k))] == 1)
						{
							flag=1;
							break;
						}
						if(A[i+k][j-(dist-abs(k))] == 1)
						{
							flag=1;
							break;
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
