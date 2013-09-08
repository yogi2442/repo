#include<stdio.h>
#include<stdlib.h>
int n;
int a[100003],b[100003],ind[100003],ans[100003];
/*void func()
{
	int len = 0,i,j;
	b[0]=0;
	ans[0]=0;
	for(i=1;i<=n;i++)
	{
		int max = 0;
		for(j=1;j<i;j++)
			if(b[j]<=b[i] && b[j]>=b[max])
				max=j;
		ans[i]=ans[max]+1;
	}
	for(i=1;i<=n;i++)
		if(ans[i]>=len)
			len=ans[i];
	printf("%d\n",len);
}*/
void func()
{
	int i,j;
	int len = 1;
	ans[0] = b[0];
	for(i=1;i<n;i++)
	{
		if(b[i]<ans[0])
		{
			ans[0]=b[i];
		}
		else if(b[i]>ans[len-1])
		{
			ans[len] = b[i];
			len++;
		}
		else
		{
			int start=0,end=len,num=b[i];
			int mid;
			while(start<=end)
			{
				mid = (start+end)/2;
				if(ans[mid]>=num)
				{
					end = mid-1;
				}
				else
				{
					start=mid+1;
				}
			}
			ans[end+1]=num;
		}
	}
	printf("%d\n",len);
}
int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			ind[a[i]]=i;
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			b[ind[a[i]]]=i;
		}
		func();
	}
	return 0;
}
