#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector< int > a(105),c(105),c2(105);
int rooms,max1,max2,next[105][105],next2[105][105],p1[105],p2[105];
int ar1[105],ar2[105];
int presence(int x)
{
	int i;
	for(i=0;i<max1;i++)
		if(ar1[i]==x)
			return 1;
	return 0;
}
int check2(int level,int begin)
{
	int i,j;
	if(level==0)
	{
		return 1;
	}
	for(i=0;i<c2[begin];i++)
	{
		if(presence(next2[begin][i])==0 && check2(level-1,next2[begin][i])==1)
			return 1;
	}
	return 0;
}
int check(int level,int begin)
{
	int i,j;
	if(level==0)
	{
		for(i=rooms-1;i>=0;i--)
		{
			if(p2[i]==max2 && presence(i)==0)
			{
				if(check2(max2-1,i)==1)
					return 1;
			}
		}
		return 0;
	}
	for(i=0;i<c[begin];i++)
	{
		ar1[max1-level]=next[begin][i];
		if(check(level-1,next[begin][i])==1)
			return 1;
	}
	return 0;
}
int main()
{
	int i,j,k,test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&rooms);
		max1=1;
		max2=1;
		for(i=0;i<rooms;i++)
		{
			scanf("%d",&a[i]);
			c[i]=0;
			c2[i]=0;
			p1[i]=1;
			p2[i]=1;
		}
		for(i=rooms-1;i>=0;i--)
		{
			for(j=i-1;j>=0;j--)
			{
				if(a[j]<a[i])
				{
					if(p1[j]<p1[i]+1)
					{
						p1[j]=p1[i]+1;
						c[j]=0;
					}
					if(p1[j]==p1[i]+1)
						next[j][c[j]++]=i;
				}
				if(a[rooms-1-j]<a[rooms-1-i])
				{
					if(p2[rooms-1-j]<p2[rooms-1-i]+1)
					{
						p2[rooms-1-j]=p2[rooms-1-i]+1;
						c2[rooms-1-j]=0;
					}
					if(p2[rooms-1-j]==p2[rooms-1-i]+1)
						next2[rooms-1-j][c2[rooms-1-j]++]=rooms-1-i;
				}
			}
		}
		for(i=0;i<rooms;i++)
		{
			if(p1[i]>max1)
				max1=p1[i];
			if(p2[i]>max2)
				max2=p2[i];
		}
		bool flag=false;
		for(i=0;i<rooms;i++)
		{
			if(p1[i]==max1)
			{
				ar1[0]=i;
				if(check(max1-1,i)==1)
				{
					flag=true;
					break;
				}
			}
		}
		if(flag==true)
			printf("%d\n",max1+max2);
		else
			printf("%d\n",max1+max2-1);
	}
	return 0;
}
