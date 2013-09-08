#include <stdio.h>
#include <stdlib.h>

void func(int*,int**,int**,int,int,int*);
int count;
int main()
{
	int n,i,j,k,l,m,maxLen,max,test,u;
	int *array,*list;
	int **length,**parent,**store;
//	scanf("%d",&test);
	for(u=0;u<10;u++)
	{
		scanf("%d",&n);
		array = (int*)malloc(sizeof(int)*n);
		for(i=0;i<n;i++)
			scanf("%d",&array[i]);
		if(n == 1)
		{
			printf("%d\n",array[0]);
			free(array);
			continue;
		}
		length = (int**)malloc(sizeof(int*)*((n*n)+1));
		parent = (int**)malloc(sizeof(int*)*((n*n)+1));
		store = (int**)malloc(sizeof(int*)*((n*n)+1));
		list = (int*)malloc(sizeof(int)*n);
		m = n*n;
		for(i=0;i<m;i++)
		{
			length[i] = (int*)malloc(sizeof(int)*n);
			parent[i] = (int*)malloc(sizeof(int)*n);
			store[i] = (int*)malloc(sizeof(int)*n);
		}
	//	printf("yogi\n");
		for(i=0;i<n;i++)
		{
			length[0][i] = 2;
			length[1][i] = 1;
			parent[0][i] = 2;
			parent[1][i] = -999999999;
			store[0][i] = 1;
		//	printf("i = %d\n",i);
		}

		for(i=1;i<n;i++)
		{
			for(j=0;j<i;j++)
			{
				if(array[j] < array[i])
				{
					max = -999999999;
					for(k=1;k<length[0][j];k++)
					{
						if(length[k][j] > max)
							max = length[k][j];
					}
					length[length[0][i]][i] = max+1;
					length[0][i]++;
					parent[parent[0][i]][i] = j;  // storing index of parent;
					parent[0][i]++;
				}
			}
		}

	//	printf("printing length and parent\n");
	/*	for(i=0;i<n;i++)
		{
			for(j=1;j<length[0][i];j++)
			{
				printf("%d %d\n",length[j][i],parent[j][i]);
			}
			printf("\n");
		}*/

		maxLen = -999999999;
		for(i=0;i<n;i++)
		{
			for(j=1;j<length[0][i];j++)
			{
				if(length[j][i] > maxLen)
				{
					for(k=0;k<n;k++)
					{
						store[0][k] = 1;     /// telling the position to store next index;
					}
					maxLen = length[j][i];
					store[store[0][i]][i] = j;
					store[0][i]++;
				}
				else if(length[j][i] == maxLen)
				{
					store[store[0][i]][i] = j;
					store[0][i]++;
				}
			}
		}

	//	printf("printing store array\n");
	//	printf("maxLen = %d\n",maxLen);
	/*	for(i=0;i<n;i++)
		{
			printf("printing for i = %d\n",i);
			for(j=1;j<store[0][i];j++)
			{
				printf("%d\n",store[j][i]);
			}
			printf("\n");
		}*/

		//	exit(0);

		count = 0;
		for(i=0;i<n;i++)
		{

			for(j=1;j<store[0][i];j++)
			{
				//  store[j][i] and i are the indices;
				for(k=0;k<count;k++)
				{
					if(list[k] != array[i])
						continue;
					else
						break;
				}
				if(k == count)
				{
					list[count++] = array[i];
				//	printf("adding to list number = %d\n",array[i]);
				}

				//	len = length[store[j][i]][i];
				//	par = parent[store[j][i]][i];

				//	func(list,count,length,parent,len,par,array,array[i]);
				func(list,length,parent,store[j][i],i,array);
			}
		}

		// sort the list array;

		printf("%d\n",count);
		for(i=count-1;i>=0;i--)
		{
			if(i == 0)
				printf("%d\n",list[i]);
			else
				printf("%d ",list[i]);
		}
	//	printf("\n");
		free(array);
		free(list);
		free(length);
		free(parent);
		free(store);
	}
	return 0;
}


void func(int *list,int **length,int **parent,int x,int y,int *array)
{
//	printf("in func length[x][y] = %d\n",length[x][y]);
	if(length[x][y] == 1)
	{
//		printf("returning\n");
		return;
	}
	int i,k;
	for(i=0;i<count;i++)
	{
		if(list[i] != array[parent[x][y]])
			continue;
		else
			break;
	}
	if(i == count)
	{
		list[count++] = array[parent[x][y]];
//		printf("adding to list in function number = %d\n",array[parent[x][y]]);
	}
	
	for(i=1;i<length[0][parent[x][y]];i++)
	{
		if(length[x][y]-1 == length[i][parent[x][y]])
		{
		//	printf("parent = %d\n",array[parent[x][y]]);
		//	func(list,length,parent,i,parent[i][parent[x][y]],array);	
			func(list,length,parent,i,parent[x][y],array);	
		}
	}
//	printf("bottom returning\n");
}
