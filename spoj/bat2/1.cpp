#include <cstdio>
#include <cstdlib>

void print(int*,int*,int);
void print1(int);

int main()
{
	int *array,*parent,*len,*done,*array1;
	int i,j,u,t,n,max,m,k,first,second;
	scanf("%d",&t);
	for(u=0;u<t;u++)
	{
		first = 0;
		second = 0;
		scanf("%d",&n);
		array = new int[n];
		parent = new int[n];
		len = new int[n];
		done = new int[n];
		array1 = new int[n];

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
		//	printf("\n%d\n",len[max]);
		first = len[max];
		print(parent,done,max);

		//	printf("\n now for decreasing\n");
		j=0;
		for(i=0;i<n;i++)
		{
			parent[i] = i;
			len[i] = 1;
			if(done[i] == 0)
			{
				array1[j++] = array[i];
				//	printf("%d ",array[i]);
			}
			done[i] = 0;
		}
		//	printf("\n");

		if(j != 0)
		{
			for(i=0;i<j;i++)
			{
				for(k=i+1;k<j;k++)
				{
					if(array1[k] < array1[i] && len[k] < len[i] + 1)
					{
						parent[k] = i;
						len[k] = len[i] + 1;
					}
				}
			}

			max = 0;
			for(i=0;i<j;i++)
			{
				if(len[max] < len[i])
					max = i;
			}

			//		printf("%d\n",len[max]);
			second = len[max];
			//	print1(max);
		}
		printf("%d\n",first+second);
			
		delete[] array;
		delete[] array1;
		delete[] parent;
		delete[] done;
		delete[] len;
	}
	return 0;
}
/*
void print1(int i)
{
	if(parent[i] == i)
	{
	//	printf("%d ",array1[i]);
		done[i] = 1;
		return ;
	}
	print(parent[i]);

//	printf("%d ",array1[i]);
	done[i] = 1;
}*/
void print(int *parent, int *done,int i)
{
	if(parent[i] == i)
	{
	//	printf("%d ",array[i]);
		done[i] = 1;
		return ;
	}
	print(parent,done,parent[i]);

//	printf("%d ",array[i]);
	done[i] = 1;
}
