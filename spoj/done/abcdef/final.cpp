#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int compare(const void *a,const void *b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	int n,j,i,k,l,m,array[101],array1[2000000],count;
//	vector<int> myvector(2);
	cin >> n;

	for(i=0;i<n;i++)
	{
		cin >> array[i];
	}
	m=0;
	for(i=0;i<n;i++)
	{
		if(array[i] != 0)
		{
			for(j=0;j<n;j++)
			{
				for(k=0;k<n;k++)
				{
					array1[m++] = (array[k]+array[j])*array[i];
				}
			}
		}
	}
	sort(array1,array1+m);
	count = 0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				
				l = (array[i]*array[j])+array[k];
				count = count + upper_bound(array1,array1+m,l) - lower_bound(array1,array1+m,l);
			}
		}
	}
	cout << count << endl;
	return 0;
}
