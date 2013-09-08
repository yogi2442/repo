#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	int test,u,i,j,k,l,n,size;
	long long m;
	int cow;
	vector< pair<long long, int> > v;
	scanf("%d",&test);
	vector< pair<long long, int> >:: iterator it,low,up;
	pair<long long,int> pa;
	int low1,high1,low2,high2;
	long long mid1,mid2;

	for(u=0;u<test;u++)
	{
		scanf("%d",&n);
		scanf("%d",&cow);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&m);
		//	pa(m,0);
		//	v[i].first = m;
		//	v[i].second = 0;

			v.push_back(make_pair(m,0));
		}
		size = v.size();
		sort(v.begin(),v.end());

		it = v.begin();
		for(;it != v.end();it++)
		{
			cout << it->first << " ";
		}
		cout << "\n";


		if(cow == 2)
		{
			cout << v[n-1].first - v[0].first << endl;
		}

		else
		{
			v[0].second = 1;
			v[n-1].second = 1;
			
			cow = cow-2;
			low1 = 0;
			high1 = n-1;
			mid1 = (v[low1].first + v[high1].first)/2;
			
			low = lower_bound(v.begin(),v.end(),make_pair(mid1,0));
			up = upper_bound(v.begin(),v.end(),make_pair(mid1,0));

			if(low == up)
			{
				// not present;
				low--;
			}
			else
			{
				// present;
			}
			cout << low->first << endl << up->first << endl;
			
		}
	}
	return 0;
}

