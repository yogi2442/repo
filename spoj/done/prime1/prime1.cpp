#include<cstdio>
#include<iostream>
#include<math.h>
#include<map>
#include<vector>
#include <cstdlib>
using namespace std;
int array[33001];
int a[33000];

int isPrime(int n){
	int i,j;
	int limit=sqrt(n);
	if(n==1)
		return 0;
	for(i=0;i<=limit;i++)
	{
		if(a[i]<=limit)
		{
			//cout<<n<<" "<<a[i]<<endl;
			if(n%a[i]==0)
				return 0;
		}
		else
			break;
	}
	return 1;
}

int main(){
	int t1,t2;
	scanf("%d",&t2);
	int k;
	for(t1=0;t1<t2;t1++)
	{
		int n1,n2;
		scanf("%d",&n1);
		scanf("%d",&n2);
		int i,j;

		for(i=2;i<=33000;i=i+1)
			array[i]=1;

		for(i=2;i<=33000;i=i+1)
		{
			if(array[i]==1)
			{
				int start=i*i;
				for(j=start;j<=33000;j=j+1)
				{
					if(array[j]==1)
					{
						if(j%i==0)
							array[j]=0;
					}
				}
			}

		}
		j=0;


		for(i=2;i<=33000;i++){
			if(array[i]==1)
			{
				a[j++]=i;
			//	if(i<31000)
			//		printf("%d\n",i);
			}
			//cout<<i<<endl;
		}
//		exit(0);

		for(i=n1;i<=n2;i++)
		{
			if(isPrime(i)==1)
				cout<<i<<endl;


		}
	}


	return 0;
}
