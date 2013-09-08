#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	set<int> s;
	int i,j,k,l,n;
	for(i=0;;i++)
	{
		scanf("%d",&n);
		s.insert(n);
		printf("%d\n",s.size());
	//	for(j=0;j<s.size();j++)
	//		printf("%d ",s[j]);
	//	printf("\n");
	}
	return 0;
}
