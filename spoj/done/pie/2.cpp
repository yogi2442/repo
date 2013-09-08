#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define PI 3.14159265358979323846264338327950 

int main()
{
	int t,u,i,j,k,l,m,n,start,end,total,f;
	double max,size;
	int A[10100];
	scanf("%d",&t);
	for(u=0;u<t;u++)
	{
		scanf("%d%d",&n,&f);
		end = n;
		f++;
		start = (n < f) ? 0 : n - f;
		for(i=0;i<n;i++)
		{
			scanf("%d",&m);
			A[i] = m*m;
		}
		sort(A,A+n);
		max = 0;
		for(i=end-1;i>=start;i--)
		{
			for(j=1;j<=f;j++)
			{
				size = (A[i]*1.0) / j;
				if(size <= max)
					break;
				total = 0;
				for(k=end-1;k>=start;k--)
				{
					total += (A[k]*1.0) / size;
					if(total >= f)
					{
						max = (max < size) ? size : max;
						break;
					}
				}
				if(total >= f)
					break;
			}
		}
		printf("%.4lf\n",PI*max);
	}
	return 0;
}

