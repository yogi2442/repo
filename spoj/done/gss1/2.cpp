#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int A[50010];

typedef struct node
{
	int left,right,maxi,total;
}node;

node head[200040];

void buildTree(int,int,int);
node query(int,int,int,int,int);

int main()
{
	int i,j,k,l;
	int n,m,sum,max,p,q;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	buildTree(1,0,n-1);
	
	scanf("%d",&m);
	node yogi;
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&p,&q);
		p--;
		q--;
		yogi = query(1,0,n-1,p,q);
		printf("%d\n",yogi.maxi);
	}

	return 0;
}

void buildTree(int ind, int low, int high)
{
	int mid;
	if(low == high)
	{
		head[ind] = (node){ A[low],A[low],A[low],A[low] };
		return ;
	}
	mid = (low+high)/2;

	buildTree(2*ind, low, mid);
	buildTree(2*ind + 1,mid+1,high);

	head[ind] = (node){ max(head[2*ind].left,head[2*ind].total + head[2*ind + 1].left),
			max(head[2*ind + 1].right, head[2*ind + 1].total + head[2*ind].right),
			max(head[2*ind].maxi,max(head[2*ind + 1].maxi, head[2*ind].right + head[2*ind + 1].left)),
			head[2*ind].total + head[2*ind + 1].total };

}

node query(int ind, int low, int high, int p, int q)
{
	int mid;
	node first,second,ans;
	mid = (low+high)/2;
	if(low == p && high == q)
	{
		ans = (node)head[ind];
		return ans;
	}
	else if(p > mid)
	{
		first = (node)query(2*ind + 1,mid+1,high,p,q);
		ans = (node)first;
		return ans;
	}
	else if(q <= mid)
	{
		second = (node)query(2*ind,low,mid,p,q);
		ans = (node)second;
		return ans;
	}

	first = (node)query(2*ind,low,mid,p,mid);
	second = (node)query(2*ind + 1,mid+1,high,mid+1,q);

	ans = (node){ max(first.left,first.total + second.left),
			max(second.right, second.total + first.right),
			max(first.maxi,max(second.maxi,first.right + second.left)),
			first.total + second.total };
	return ans;
}

