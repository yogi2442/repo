#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int n,i,j,A[6000],B[6000] = {0},k,count,siz,diff,numfind;
	vector<int> v;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	count=0;
	for(i=1;i<n;i++)
	{
		if(B[i] == 0)
		{
			diff = A[i] - 1;
			v.push_back(i);
			numfind = A[i] + diff;
			for(j=i+1;j<n;j++)
			{
				if(numfind == A[j])
				{
					numfind = A[j] + diff;
					v.push_back(j);
				}
				else if(numfind < A[j])
					break;
			}
			if(j == n)
			{
				count++;
				siz = v.size();
				for(k=0;k<siz;k++)
				{
					B[v[k]] = 1;
				}
			}
			v.clear();
		}
	}
	if(count == 0)
		printf("1\n");
	else
		printf("%d\n",count);
	return 0;

}
