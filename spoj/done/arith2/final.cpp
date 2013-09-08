#include <cstdio>

int main()
{
	long long test,u,i,j,k,l,n,m,ans;
	scanf("%lld",&test);
	char ch,op;
	for(u=0;u<test;u++)
	{
		ans = 0;
		scanf("%c",&ch);
		while(ch == ' ' || ch == '\n')
			scanf("%c",&ch);
		m = 0;
		while(ch >= '0' && ch <= '9')
		{
			n = ch - '0';
			m = m*10 + n;
			scanf("%c",&ch);
		}
	//	printf("m = %lld\n",m);
		ans = m;
		while(1)
		{
		//	printf("ans = %lld\n",ans);

			while(ch != '+' && ch!= '-' && ch != '*' && ch != '/' && ch != '=')
			{
				scanf("%c",&ch);
			}
			op = ch;
		//	printf("operator = %c\n",ch);
			if(ch == '=')
				break;
			
			scanf("%c",&ch);
			while(ch == ' ' || ch == '\n')
				scanf("%c",&ch);
			m = 0;
			while(ch >= '0' && ch <= '9')
			{
				n = ch - '0';
				m = m*10 + n;
				scanf("%c",&ch);
			}
		//	printf("m = %lld\n",m);
			
			if(op == '+')
				ans = ans + m;
			else if(op == '-')
				ans = ans - m;
			else if(op == '*')
				ans = ans * m;
			else if(op == '/')
				ans = ans / m;
		}
	//	printf("final ans = %lld\n",ans);
		printf("%lld\n",ans);

	}
	return 0;
}
