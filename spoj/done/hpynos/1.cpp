#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	int n,p,q,count,i;
	int flag=0;

	vector<int> v;

	flag = 0;
	scanf("%d",&n);
	count =0;
	while(n!=1)
	{
		count++;
		q = 0;
		while(n>0)
		{
			p = n%10;
			q = q + p*p;
			n = n/10;
		}

		n = q;

		if(find(v.begin(),v.end(),q) != v.end())
		{
			// yes present;
			flag=1;
			printf("-1\n");
			break;
		}
		else
		{
			v.push_back(q);
		}
	}
	if(flag==0)
		printf("%d\n",count);
	return 0;

}
