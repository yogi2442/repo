#include <cstdio>
#include <cstdlib>
#include <set>

using namespace std;

void print(int*,int*,int,int);
set<int> f[100],s[100];

int main()
{
	int *array,*parent,*len,*done,count,*max1,*max2;
	int i,j,u,t,n,max,m,k;
	scanf("%d",&t);
	for(u=0;u<t;u++)
	{
		scanf("%d",&n);
		array = new int[n];
		parent = new int[n];
		len = new int[n];
		done = new int[n];
		max1 = new int[n];

		for(i=0;i<n;i++)
		{
			scanf("%d",&array[i]);
			parent[i] = i;
			len[i] = 1;
			done[i] = 0;
		}

		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(array[j] > array[i] && len[i] + 1 > len[j])
				{
					parent[j] = i;
					len[j] = len[i]+1;
				}
			}
		}

		max = 0;
		for(i=0;i<n;i++)
		{
			//	printf("%d ",len[i]);
			if(len[i] > len[max])
				max = i;
		}
		l = 1;
		for(i=0;i<n;i++)
		{
			if(len[i] == len[max])
			{
				print(parent,done,i,l++);
			}
		}
		//	printf("\n%d\n",len[max]);
	//	print(parent,done,max);

		for(i=0;i<n;i++)
		{
			parent[i] = i;
			len[i] = 1;
		}
		for(i=0;i<n;i++)
		{
			for(k=i+1;k<n;k++)
			{
				if(array[k] < array[i] && len[k] < len[i] + 1)
				{
					parent[k] = i;
					len[k] = len[i] + 1;
				}
			}
		}

		max = 0;
		for(i=0;i<n;i++)
		{
			if(len[max] < len[i])
				max = i;
		}

		print(parent,done,max);
		
		count = 0;
		for(i=0;i<n;i++)
		{
			if(done[i] != 0)
				count++;
		}

		printf("%d\n",count);

		delete[] array;
		delete[] parent;
		delete[] done;
		delete[] len;
	}
	return 0;
}
void print(int *parent, int *done,int i,int l)
{
	if(parent[i] == i)
	{
	//	printf("%d ",array[i]);
		done[i] = l;
		return ;
	}
	print(parent,done,parent[i],l);

//	printf("%d ",array[i]);
	done[i] = l;
}
