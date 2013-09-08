#include <cstdio>
#include <cstdlib>

char str[32000],ch;

void func(int,int,int);
void update(int,int,int,int);

typedef struct node
{
	int open;
	int close;
}node;

node tree[65537];

int main()
{
	int i,j,k,l,m,n,len,u;
	for(u=0;u<10;u++)
	{
		scanf("%d",&len);
		scanf("%s",str);
	//	printf("%s\n",str);	
		func(1,0,len-1);
		printf("Test %d:\n",u+1);
		scanf("%d",&n);
	//	printf("n = %d\n",n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&m);
	//		printf("m = %d\n",m);
			if(m > 0)
				update(1,0,len-1,m-1);
			else
			{
				if(tree[1].close == 0  && tree[1].open == 0)
					printf("YES\n");
				else
					printf("NO\n");
			}
		}
	}
	return 0;
}

void update(int ind,int low, int high, int m)
{
	if(low ==  m && high == m) 
	{
		if(tree[ind].open == 1)
		{
			tree[ind].close = 1;
			tree[ind].open = 0;
		}
		else
		{
			tree[ind].close = 0;
			tree[ind].open = 1;
		}
		return ;
	}

	int p,q,r,mid;
	mid = (low+high)/2;
	if(m >= low && m <= mid)
		update(2*ind,low,mid,m);
	else if(m >= mid+1 && m <= high)
		update(2*ind + 1,mid+1,high,m);
	
	if(tree[2*ind].open > tree[2*ind + 1].close)
	{
		tree[ind].close = tree[2*ind].close;
		tree[ind].open = tree[2*ind + 1].open + (tree[2*ind].open - tree[2*ind + 1].close);
	}
	else
	{
		tree[ind].open = tree[2*ind + 1].open;
		tree[ind].close = tree[2*ind].close + (tree[2*ind + 1].close - tree[2*ind].open);
	}
//	tree[ind].sum = tree[2*ind].sum + tree[2*ind +1].sum;
//	tree[ind].open = ((tree[2*ind].open + tree[2*ind + 1].sum) > tree[2*ind + 1].open ? tree[2*ind].open + tree[2*ind +1].sum : tree[2*ind + 1].open); 
//	printf("range %d - %d = array position = %d\n",low,high,ind);
}

void func(int ind,int low,int high)
{
	if(low == high)
	{
		if(str[low] == ')')
		{
			tree[ind].close = 1;
			tree[ind].open = 0;
		}
		if(str[low] == '(')
		{
			tree[ind].close = 0;
			tree[ind].open = 1;
		}
//		printf("bracket position = %d and Array position = %d\n",low,ind);
		return ;
	}
	func(2*ind,low,(low+high)/2);
	func(2*ind + 1,(low+high+2)/2,high);
	
	if(tree[2*ind].open > tree[2*ind + 1].close)
	{
		tree[ind].close = tree[2*ind].close;
		tree[ind].open = tree[2*ind + 1].open + (tree[2*ind].open - tree[2*ind + 1].close);
	}
	else
	{
		tree[ind].open = tree[2*ind + 1].open;
		tree[ind].close = tree[2*ind].close + (tree[2*ind + 1].close - tree[2*ind].open);
	}

//	tree[ind].sum = tree[2*ind].sum + tree[2*ind +1].sum;
//	tree[ind].open = ((tree[2*ind].open + tree[2*ind + 1].sum) > tree[2*ind + 1].open ? tree[2*ind].open + tree[2*ind +1].sum : tree[2*ind + 1].open); 

//	printf("range %d - %d = array position = %d\n",low,high,ind);
}
