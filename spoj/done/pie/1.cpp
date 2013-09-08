#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define PI 3.14159265358979323846264338327950 
int f;

int check(double [],int,int, double);

int main()
{
	int t,u,i,j,k,l,m,n,start,end,total;
	double high,low,mid;
	double A[10100];
	scanf("%d",&t);
	for(u=0;u<t;u++)
	{
		scanf("%d%d",&n,&f);
		high = 0;
		end = n;
		f++;
		start = (n < f) ? 0 : n - f;
		for(i=0;i<n;i++)
		{
			scanf("%d",&m);
			A[i] = m*m*1.0;
		}
		sort(A,A+n);
		low = 0;
		high = A[end-1];

		total = 100;
		while(total--)
		{
			mid = ((low + high)*1.0)/2.0;
		//	printf("%lf %lf %lf\n",low,mid,high);
			if(check(A,start,end,mid) == 1)
				low = mid;
			else
				high = mid;
		}
		printf("%.4lf\n",PI*low);
	}
	return 0;
}

int check(double A[], int start, int end, double mid)
{
	int i,total=0;
	for(i=end-1;i>=start;i--)
	{
		total += A[i] / mid;
	}
	if(total >= f)
		return 1;
	else
		return 0;
}
