#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

long long func(long long);
//vector< pair < long long,long long > > v;
map< long long, long long > :: iterator it;
map<long long, long long> m;


int main()
{
	long long n,m,i,j,ans,ans1;
	while(scanf("%lld",&n) != EOF)
	{
		ans1 = func(n);
	//	if(ans1 < n)
	//		printf("%lld\n",n);
	//	else
			printf("%lld\n",ans1);
	}
	return 0;
}

long long func(long long n)
{
	if(n == 0)
		return 0;

	it = m.find(n);
	if(it == m.end())
	{
		long long i,j,k,l;
		i = func(n/2);
		j = func(n/3);
		k = func(n/4);

		l= i + j + k;

		if(l < n)
		{	
			m.insert(pair<long long,long long> (n,n));
			return n;
		}
		else
		{
			m.insert(pair<long long,long long> (n,l));
			return l;
		}
	}
	else
	{
		return it->second;
	}
}
