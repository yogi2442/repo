#include <stdio.h>
int main()
{
	int A[] = {0, 0, 6, 12, 90, 360, 2040, 10080, 54810, 290640, 1588356, 8676360, 47977776, 266378112, 1488801600};
	int t,n,u;
	scanf("%d",&t);
	for(u=0;u<t;u++)
	{
		scanf("%d",&n);
		printf("%d\n",A[n]);
	}
	return 0;
}
