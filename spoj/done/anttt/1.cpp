#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int A[1001][1001],x1[1001],y1[1001],x2[1001],y2[1001];

int check(int,int);
int anotherCheck(int,int);
int query(int,int);

int main()
{
	int i,j,l,k,m,n,t,u,p,q,ans,ans1;
	scanf("%d",&t);

	for(u=0;u<t;u++)
	{
		scanf("%d%d",&n,&m);
		scanf("%d%d%d%d",&x1[1],&y1[1],&x2[1],&y2[1]);
		A[1] = 0;
		for(i=2;i<=n;i++)
		{
			scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
			for(j=i-1;j>=1;j--)
			{
				ans1 = check(i,j);
				if(ans1 < 0)
				{
					if(check(j,i) < 0)
					{
						A[i] = j;
					//	printf("intersect\n");
						break;
					}
				}
				else if(ans1 == 0)
				{
					if(anotherCheck(i,j) < 0 || anotherCheck(j,i) < 0)
					{
						A[i] = j;
					//	printf("intersect\n");
						break;
					}
				}
			}
			if(j == 0)
			{
			//	printf("do not intersect\n");
				A[i] = 0;
			}

		}

		for(i=0;i<m;i++)
		{	
			scanf("%d%d",&p,&q);
			if(p == q)
				printf("YES\n");
			else
			{
				if(p > q)
					ans = query(q,p);
				else
					ans = query(p,q);
				if(ans == 1)
					printf("YES\n");
				else
					printf("NO\n");
			}
		}
	}
	return 0;
}

int query(int dest, int start)
{
	if(A[start] == 0)
		return 0;
	else if(A[start] == dest)
		return 1;
	else
	{
		return query(dest,A[start]);
	}
}

int check(int line, int point)
{
	int c1,c2,c3,c4;

	c1 = (x2[line] - x1[line])*(y1[point] - y2[line]) - (y2[line] - y1[line])*(x1[point] - x2[line]);
	c2 = (x2[line] - x1[line])*(y2[point] - y2[line]) - (y2[line] - y1[line])*(x2[point] - x2[line]);
//	printf("%d\n",c1*c2);
	c3 = c1*c2;
	return c3;
}

int anotherCheck(int line, int point)
{
	int c1,c2,c3,c4;
		c1 = min(x1[line],x2[line]);
		c2 = max(x1[line],x2[line]);
		c3 = min(y1[line],y2[line]);
		c4 = max(y1[line],y2[line]);

		if(c1 <= x1[point] && x1[point] <= c2 && c3 <= y1[point] && y1[point] <= c4)
			return -1;
		if(c1 <= x2[point] && x2[point] <= c2 && c3 <= y2[point] && y2[point] <= c4)
			return -1;

/*
	c1 = (x2[line] - x1[line])*(x1[point] - x1[line]) + (y2[line] - y1[line])*(y1[point] - y1[line]);
	//	printf("c1 = %d\n",c1);
	if(c1 >= 0 && c1 <= ((x2[line] - x1[line])*(x2[line] - x1[line]) + (y2[line] - y1[line])*(y2[line] - y1[line])))
		return -1;
	c1 = (x2[line] - x1[line])*(x2[point] - x1[line]) + (y2[line] - y1[line])*(y2[point] - y1[line]);
	if(c1 >= 0 && c1 <= ((x2[line] - x1[line])*(x2[line] - x1[line]) + (y2[line] - y1[line])*(y2[line] - y1[line])))
		return -1;
*/
	return 0;
			
}

