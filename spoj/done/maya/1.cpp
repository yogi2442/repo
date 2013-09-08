#include <cstdio>

int main()
{
	long long ans;
	int i,j,k,l,n,dot,hypen,zero;
	char ch;
	int A[] = {1,1,20,360,7200,144000,2880000,57600000};
	scanf("%d",&n);

	while(n != 0)
	{
		scanf("%c",&ch);
		ans=0;
		while(n)
		{
			dot=0;
			hypen=0;
			zero=0;
			scanf("%c",&ch);
			while(ch != '\n')
			{
				if(ch == '.')
					dot++;
				else if(ch == '-')
					hypen++;
				else if(ch == 'S')
					zero=1;
				scanf("%c",&ch);
			}
			l = (hypen*5)+dot;
			ans = ans + (l*A[n]);
			n--;
		}
		printf("%lld\n",ans);
		scanf("%d",&n);
	}
	return 0;
}
