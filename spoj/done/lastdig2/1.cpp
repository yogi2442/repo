#include <cstdio>
#include <cstring>
int main()
{
	long long i,j,k,l,m,n,t,u;
	char c[1009];
	int A[] = {1,1,4,4,2,1,1,4,4,2};
	scanf("%lld",&t);
	while(t)
	{
		scanf("%s%lld",c,&n);
		if(n == 0)
		{
			printf("1\n");
			t--;
			continue;
		}
		m = c[strlen(c)-1]-'0';
	//	printf("m = %lld and n = %lld\n",m,n);
		n = n%A[m];
		n = (n==0) ? n=A[m] : n;
		l=1;
		while(n)
		{
			l=l*m;
			n--;
		}
		printf("%lld\n",l%10);
		t--;
	}
}
