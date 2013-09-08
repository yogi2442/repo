#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>

int main()
{
	int time1[101],time2[101];
	int i,j,k,l,n,m;
	int test,u,max;
	scanf("%d",&test);
	for(u=0;u<test;u++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d%d",&time1[i],&time2[i]);
		sort(time1,time1+n);
		sort(time2,time2+n);

		i=0;j<0;
		k=0;max=0;
		while(i<n && j<n)
		{
			if(time1[i] < time1[j])
			{
				k++;
				i++;
			}
			else
			{
				k--;
				j++;
			}
			if(max < k)
				max = k;
		}
		printf("%d\n",max);
	}

}
