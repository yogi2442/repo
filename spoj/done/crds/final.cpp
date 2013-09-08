#include <cstdio>
#include <iostream>


using namespace std;
int main()
{
	long long n,m;
	int i,j,k,l,test,u;
	cin >> test;
	for(u=0;u<test;u++)
	{
		cin >> n;
		m = (n*(n+1))/2;
		m = 3*m - n;
		m = m % 1000007;
		cout << m << endl;
	}
	return 0;

}
