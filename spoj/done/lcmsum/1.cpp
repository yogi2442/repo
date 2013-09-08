#include <cstdio>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	long long int test,u,i,n,p,q,r,m;
	long long int ans1,ans2;
	int flag;
	cin >> test;
	for(u=0;u<test;u++)
	{
		cin >> n;
		ans2 = n;
		m = n/2;
		flag = 0;
		if(n%2 == 0)
			flag = 1;
		for(i=1;i<=m;i++)
		{
			p = i;
			q = n;
			r = 1;
			while(r != 0)
			{
				r = p % q;
				p = q;
				q = r;
			}
			ans1 = (n / p) * i;
			ans2 = ans2 + ans1;
			ans1 = (n / p)*(n-i);
			ans2 = ans2 + ans1;
		}
		if(flag == 1)
		{
			ans2 = ans2 - ans1;
		}
		cout << ans2 << endl;
	}
	return 0;


}
